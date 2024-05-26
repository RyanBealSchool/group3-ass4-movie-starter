#ifndef INVENTORY_H
#define INVENTORY_H
#include "hash_table.h"
#include "movie.h"
#include "media.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <iterator>
#include "customer.h"
using namespace std;

class Inventory {
private:
  //priority_queue<Media> sortedMovies;
  HashTable hashTable;
  vector<Customer> customers;
  priority_queue<Movie> sortedMovies;
  string generateUniqueKey(Media *m);

public:
  void addMedia(Media *m); //adds the media to the hashtable
  Media *getMedia(string title); //if doesMediaExist = true, finds & returns media
  bool doesMediaExist(string title); //checks if the media exists in the hashtable
  int indexOfMedia(string title); //index of where media is stored in the hashtable
  void printCustomerList(); //prints out a list of all registered customers
  void printMediaList(); //prints out a list of all stored media
};
#endif