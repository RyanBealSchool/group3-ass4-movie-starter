#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Customer {

private:
  int customerID;
  string lastName;
  string firstName;
  vector<pair<char, string>> history;

public:
  Customer(int id, std::string ln, std::string fn);
  int getCustomerID();
  string getLastName();
  string getFirstName();
  bool hasMovie(string title);
  bool borrowMovie(string title);
  bool returnMovie(string title);
  void printHistory();
  string toCustomerString() const;
};
#endif
