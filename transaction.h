#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <vector>
#include "customer.h"
#include "movie.h"

class Transaction {
private:
  char type;
  char command;

public:
  //empty
  Transaction();
  //inventory
  Transaction(char t);
  //history
  Transaction(char t, int id);
  //borrow and return
  Transaction(char t, int id, char medt, char movt, Media m);
  char getType();
  char getAction();
};
#endif


