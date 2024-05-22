#include "movie.h"
#include <map>

class HashTable {
private:
  map<int, Movie *> table;
  int tableSize;
  int hashFunction(int key);

public:
  HashTable();
  void addMovie(Movie *movie);
  Movie *findMovie(string key);
};
