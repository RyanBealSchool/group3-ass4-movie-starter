#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "transaction.h"
#include "inventory.h"
class Commands {
private:

//storing the transactions in a vector so they can be read in more easily
vector<Transaction*> transactions;
unordered_map<int, Customer*> customers;
Inventory I;


bool validTransaction(vector<string> tokens);
Transaction* createTransaction(vector<string> tokens);
string combineTokens(vector<string> tokens, int& start);

public:
  bool readMoviesFile();
  bool readCustomersFile();
  bool readCommandsFile();
  void excecute(Transaction* t);
  void executeTransactions();
};
