#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <vector>
#include "customer.h"
#include "movie.h"

class Transaction {
private:
  Customer *customer;
  Movie *movie;
  char type;
  char command;
  vector<Transaction*> transactions;

public:
  Transaction(Customer *c, Movie *m, char t, char a);
  Customer *getCustomer();
  Movie *getMovie();
  char getType();
  char getAction();
  void addTransaction(Transaction *t);
  void displayHistory();
};
#endif


