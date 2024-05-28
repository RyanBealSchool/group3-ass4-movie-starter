#ifndef INVENTORY_H
#define INVENTORY_H
#include "customer.h"
#include "hash_table.h"
#include "media.h"
#include "movie.h"
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Inventory {
private:
  // priority_queue<Media> sortedMovies;
  HashTable hashTable;
  vector<Customer> customers;
  string generateUniqueKey(Media *m);

public:
  void addMedia(Media *m); // adds the media to the hashtable
  Media *
  getMedia(Media *m); // if doesMediaExist = true, finds & returns media
  bool doesMediaExist(Media *m); // checks if the media exists in the hashtable
  int indexOfMedia(Media *m); // index of where media is stored in the hashtable
  void printCustomerList(); // prints out a list of all registered customers
  void printMediaList();    // prints out a list of all stored media
};
#endif