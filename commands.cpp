#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "commands.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"

bool Commands::readMoviesFile() {
	// assuming that the movies files is always data4movies.txt
	ifstream file;
	file.open("data4movies.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			stringstream lstream(line);
			Media *m;
			if (line[0] == 'F') {
				Comedy *c = new Comedy();
				lstream >> *c;
				m = c;
				this->I.addMedia(m);
			} else if (line[0] == 'D') {
				Drama *d = new Drama();
				lstream >> *d;
				m = d;
				this->I.addMedia(m);
			} else if (line[0] == 'C') {
				Classic *c = new Classic();
				lstream >> *c;
				m = c;
				this->I.addMedia(m);
			} else {
				cout << "invalid code: " << line[0] << endl;
			}
		}
	}
	return false; 
}

vector<string> tokenize(string line) {
	stringstream ss(line);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> tokens(begin, end);
	return tokens;    
}

string Commands::combineTokens(vector<string> tokens, int start)
{
	string returnValue;
	while(start < tokens.size() && tokens[start-1].back() != ',') {
		returnValue += tokens[start] + " ";
		start++;
	}
	return returnValue;
}

void printTokens(vector<string> tkns) {
	for (string s: tkns) {
		cout << s << " ";
	}
	cout << endl;
}

bool Commands::validTransaction(vector<string> tokens) {
	if (tokens.size() == 1 && tokens[0] == "I") {
    	return true;
	}

  	if ((tokens[0] != "H" && tokens[0] != "B" && tokens[0] != "R")) {
    	cout << "Invalid command code: " << tokens[0] << endl;
    	return false;
  	}
	
	if (customers.find(stoi(tokens[1])) == customers.end()) {
    	cout << "Customer with ID = " << tokens[1] << " does not exist" << endl;
    	return false;
  	}
  	if (tokens[0] == "H" && tokens.size() == 2) {
    	return true;
	}

  	if (tokens[2] != "D") {
    	cout << "Invalid media type: " << tokens[2] << endl;
    	return false;
  	}	

  	if ((tokens[3] != "D" && tokens[3] != "F" && tokens[3] != "C")) {
    	cout << "Unsupported movie type: " << tokens[3] << endl;
    	return false;
  	}	
	Media *media = nullptr;
  	if (tokens[3] == "D") {
    	string director = combineTokens(tokens, 4);
    	string title = combineTokens(tokens, 5);
    	media = new Drama(0, director, title, 0);
  	} else if (tokens[3] == "F") {
    	string title = combineTokens(tokens, 4);
    	int year = stoi(tokens.back());
    	media = new Comedy(0, "", title, year);
  	} else if (tokens[3] == "C") {
    	string actor = combineTokens(tokens, 4);
    	int month = stoi(tokens[4]);
    	int year = stoi(tokens[5]);
    	media = new Classic(0, "", "", actor, month, year);
  	}

  	if (media) {
    	bool mediaExists = I.doesMediaExist(media);
    	delete media;
    	return mediaExists;
  	}
  	return false;
}

Transaction* Commands::createTransaction(vector<string> tokens) {
	if(tokens[0] == "I") {
		Transaction* t = new Transaction(tokens[0]);
        return t;
    }
	if(tokens[0] == "H")
    {
		Transaction* t = new Transaction(tokens[0], stoi(tokens[1]));
        return t;
    }

	if (tokens[3] != "C") {
		// non-classic borrow/return
		string movieTitle;
		Movie* m;
		if (tokens[3] == "F") {
			// it's a funny movie.
			movieTitle = combineTokens(tokens, 4);
		} else if (tokens[3] == "D") {
			// it's a drama movie
			int i = tokens.size() - 1;
			movieTitle += tokens[i];
			i--;
			while (i >= 0 && tokens[i].back() != ',') {
				string tmp = tokens[i] + " " + movieTitle;
				movieTitle = tmp;
				i--;
			}
		} else {
			return nullptr;
		}

		// TODO uncomment this as well for it to work after finding things works as expected. 
		// m = (Movie*) I.getMedia(movieTitle);
		// Transaction* t = new Transaction(
		// 	tokens[0], 
		// 	stoi(tokens[1]), 
		// 	tokens[2], 
		// 	tokens[3],
		// 	m->getStock(), 
		// 	m->getDirector(),
		// 	m->getTitle(),
		// 	m->getYear());
		return nullptr;
	} 

	return nullptr;
}

bool Commands::readCustomersFile() { 
	// assuming that the customers file is always data4customers.txt
	ifstream file;
	file.open("data4customers.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			vector<string> tokens = tokenize(line);
			int id = stoi(tokens[0]);
			Customer* c = new Customer(id, tokens[1], tokens[2]);
			this->customers[id] = c;
		}
	}
	return true; 
}


bool Commands::readCommandsFile() { 
	// assuming that the movies files is always data4commands.txt
	ifstream file;
	file.open("data4commands.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			// line.erase(remove(line.begin(), line.end(), ','), line.end());
			vector<string> tokens = tokenize(line);
			if(validTransaction(tokens)) {
				cout << "the following transaction is valid: " << endl;
				printTokens(tokens);
				// printTokens(tokens);
				transactions.push_back(createTransaction(tokens));
			} else {
				cout << "invalid transaction: " << line << endl;
			}
		}
	}
	return true;
}

void Commands::excecute(Transaction* t)
{
	if(t->getType() == "I")
	{
		cout << "Inventory:" << endl;
		I.printMediaList();
		cout << endl;
	}
	else if(t->getType() == "H")
	{
		cout << "History:" << endl;
		for(auto x : customers)
		{
			x.second->printHistory();
		}
		cout << endl;
	}
	else if(t->getType() == "B")
	{
		if(customers.at(t->getId())->borrowMovie(t->getMovieTitle()))
		{
			
		}
		
		//add borrowing from hashtable
	}
	else if(t->getType() == "R")
	{
		customers.at(t->getId())->returnMovie(t->getMovieTitle());
		//add borrowing from hashtable
	}
	else
	{
		return;
	}		
}

void Commands::executeTransactions()
{
	for(int i = 0; i < this->transactions.size(); i++)
	{
		excecute(transactions[i]);
	}
}