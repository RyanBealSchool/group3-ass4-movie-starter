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
  int id;
  char medt;
  char movt;
public:
  //empty
  Transaction();
  //inventory
  Transaction(char t);
  //history
  Transaction(char t, int id);
  //borrow and return for non classic
  Transaction(char t, int id, char medt, char movt, int stock, string director, string title, int year);
  //borrow and return for classic
  Transaction(char t, int id, char medt, char movt, int stock, string director, string title, int year, string actor, int date);
  char getType();
  char getAction();
  char getMediaType();
  char getMovieType();
  int getId();
};
#endif


