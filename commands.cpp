#include <fstream>
#include <sstream>
#include <iterator>
#include "commands.h"
#include "comedy.h"

bool Commands::readMoviesFile() {
	// assuming that the movies files is always data4movies.txt
	ifstream file;
	file.open("data4movies.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			stringstream lstream(line.substr(3));
			cout << line.substr(3) << endl;
			if (line[0] == 'F') {
				// Comedy *c = new Comedy();
				// lstream >> *c;
			} else if (line[0] == 'D') {

			} else if (line[0] == 'C') {

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

bool Commands::validTransaction(vector<string> tokens)
{
	if(tokens[0] != "I" || tokens[0] != "H" || tokens[0] != "B" || tokens[0] != "R")
    {
        return false;
    }
    else if(customers[stoi(tokens[1])] == nullptr)
	{
		return false;
	}
    else if(tokens[2] != "D")
    {
        return false;
    }
    else if(tokens[3] != "D" || tokens[3] != "F" || tokens[3] != "C")
    {
        return false;
    }
	//This is not complete
    else if (!I.doesMediaExist("tmp"))
    {
        return false;
    }
	else
	{
		return true;
	}
}

Transaction Commands::createTransaction(vector<string> tokens)
{
	if(tokens[0] == "I")
    {
		Transaction* t = new Transaction(tokens[0]);
        return *t;
    }
	if(tokens[0] == "H")
    {
		Transaction* t = new Transaction(tokens[0], stoi(tokens[1]));
        return *t;
    }

	//incomplete past here
	if(tokens[0] == "B" && tokens[3] != "C")
    {
		Transaction* t = new Transaction();
        return *t;
    }
	if(tokens[0] == "R" && tokens[3] != "C")
    {
		Transaction* t = new Transaction();
        return *t;
    }
	if(tokens[0] == "B" && tokens[3] == "C")
    {
		Transaction* t = new Transaction();
        return *t;
    }
	if(tokens[0] == "R" && tokens[3] == "C")
    {
		Transaction* t = new Transaction();
        return *t;
    }
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
			vector<string> tokens = tokenize(line);
			if(validTransaction(tokens))
			{
				transactions[i] = createTransaction(tokens);
			}
		}
	}
}


