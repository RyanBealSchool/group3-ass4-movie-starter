#include <fstream>
#include <sstream>
#include <iterator>
#include "commands.h"

bool Commands::readMoviesFile() {
	return false; 
}

vector<string> tokenize(string line) {
	stringstream ss(line);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> tokens(begin, end);
	return tokens;    
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
			Customer c(id, tokens[1], tokens[2]);
			this->customers[id] = c;
		}
	}

	return true; 
}

bool Commands::readCommandsFile() { 
	return false; 
}

void displayHistory() {

}


