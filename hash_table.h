#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <functional>
#include "media.h"
#include "movie.h"
using namespace std;

class HashTable {
private:
  int tableSize;
  struct HashEntry {
        string key;
        Media* media;
    };
    unordered_map<string, HashEntry> table;
    //map<int, Movie *> table;

public:
  HashTable();
  //void addMovie(Movie *movie);
  bool add(const string& key, Media* media);
  Media *findMovie(string key);
  int hashFunction(int key);
  int getTableSize();
};
#endif
