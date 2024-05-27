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
		cout << "invalid command code: " << tokens[0] << endl;
		return false;
	}

	if (customers[stoi(tokens[1])] == nullptr) {
		cout << "customer with id = " << tokens[1] << " does not exist" << endl;
		return false;
	}

	if (tokens[0] == "H" && tokens.size() == 2) {
		return true;
	}

	if (tokens[2] != "D") {
		cout << "invalid media type: " << tokens[2] << endl;
		return false;
	}

	if ((tokens[3] != "D" && tokens[3] != "F" && tokens[3] != "C")) {
		cout << "unsupported movie type: " << tokens[3] << endl;
		return false;
	}

	if (tokens[3] == "D") {
		// it's a drama film
		string movieTitle;
		int i = tokens.size() - 1;
		movieTitle += tokens[i];
		i--;
		while (i >= 0 && tokens[i].back() != ',') {
			string tmp = tokens[i] + " " + movieTitle;
			movieTitle = tmp;
			i--;
		}
		movieTitle = movieTitle.substr(0, movieTitle.length() - 1);
		return I.doesMediaExist(" " + movieTitle);
	} 

	if (tokens[3] == "F") {
		string movieTitle = combineTokens(tokens, 4);
		// return I.doesMediaExist(movieTitle);
		return true;
	}

	if (tokens[3] == "C") {
		// TODO: need a way to check the actor.
		return true;
	}
	
	return false;
}

Transaction* Commands::createTransaction(vector<string> tokens) {
	// if(tokens[0] == "I") {
	// 	Transaction* t = new Transaction(tokens[0]);
    //     return t;
    // }
	// if(tokens[0] == "H")
    // {
	// 	Transaction* t = new Transaction(tokens[0], stoi(tokens[1]));
    //     return t;
    // }

	// //incomplete past here
	// if(tokens[0] == "B" && tokens[3] != "C")
    // {
	// 	Transaction* t = new Transaction();
    //     return t;
    // }
	// if(tokens[0] == "R" && tokens[3] != "C")
    // {
	// 	Transaction* t = new Transaction();
    //     return t;
    // }
	// if(tokens[0] == "B" && tokens[3] == "C")
    // {
	// 	Transaction* t = new Transaction();
    //     return t;
    // }
	// if(tokens[0] == "R" && tokens[3] == "C")
    // {
	// 	Transaction* t = new Transaction();
    //     return t;
    // }
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
	int i = 0;
	file.open("data4commands.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			// line.erase(remove(line.begin(), line.end(), ','), line.end());
			vector<string> tokens = tokenize(line);
			if(validTransaction(tokens)) {
				// cout << "valid transaction" << endl;
				transactions[i] = createTransaction(tokens);
				i++;
			} else {
				cout << "invalid transaction: " << line << endl;
			}
		}
	}
	return true;
}
