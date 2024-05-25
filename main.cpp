/**
 * Driver for starting movie store tests
 */

#include <iostream>
#include "commands.h"

using namespace std;

// forward declaration, implementation in store_test.cpp
void testAll();

int main() {
  Commands c;
  c.readMoviesFile();
  // c.readCustomersFile();
  // c.readCommandsFile();

  cout << "Done." << endl;
  return 0;
}
