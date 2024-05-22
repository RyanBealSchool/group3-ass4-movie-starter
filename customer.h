#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
using namespace std;

class Customer {

private:
  int customerID;
  string lastName;
  string firstName;

public:
  Customer(int id, std::string ln, std::string fn);
  int getCustomerID();
  string getLastName();
  string getFirstName();
};
#endif
