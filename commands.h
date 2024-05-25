#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "transaction.h"
class Commands {
private:

//storing the transactions in a vector so they can be read in more easily
//transactions are able to be printed using operator overload of Transaction class
vector<Transaction> transactions;
unordered_map<int, Customer> customers;

public:
  bool readMoviesFile();
  bool readCustomersFile();
  bool readCommandsFile();
  void displayHistory();

  //this might need to be broken up into different functions
  void executeCommands();
};
