#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <vector>
#include "customer.h"
#include "media.h"
#include "hash_table.h"
#include "inventory.h"

class Transaction {
private:
  string type;
  string medt;
  string movt;
  string title;
  string director;
  string year;
  string actor;
  int id;
  Media* m;
public:
  //empty
  Transaction();
  //inventory
  Transaction(string t);
  //history
  Transaction(string t, int id);
  //borrow and return for non classic
  Transaction(string t, int id, string medt, string movt, int stock, string director, string title, int year);
  //borrow and return for classic
  Transaction(string t, int id, string medt, string movt, int stock, string director, string actor, int year, string c);

  Transaction(string t, int id, string medt, string movt, Media* m) {
    this->type = t;
    this->id = id;
    this->medt = medt;
    this->movt = movt;
    this->m = m;
    this->title = m->getTitle();
  }

  Media* getMedia() {
    return m;
  }

  string getType();
  string getMediaType();
  string getMovieType();
  string getMovieTitle();
  int getId();
};
#endif


