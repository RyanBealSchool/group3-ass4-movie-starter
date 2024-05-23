#include "customer.h"

Customer::Customer(int id, string ln, string fn) {
    this->customerID = id;
    this->lastName = ln;
    this->firstName = fn;
}

int Customer::getCustomerID() { 
    return customerID;
}

string Customer::getLastName() { 
    return lastName;
}

string Customer::getFirstName() { 
    return firstName; 
}

bool Customer::hasMovie(string title) {
    for (int i = 0; i <= borrowedMovies.size(); i++) {
        if (borrowedMovies[i] == title) {
            return true;
        }
    } 
    return false; 
}

bool Customer::borrowMovie(string title) {
    for (int i = 0; i <= borrowedMovies.size(); i++) {
        if (borrowedMovies[i] == title) {
            return false;
        }
    }
    borrowedMovies.push_back(title);
    return true;
}

bool Customer::returnMovie(string title) {
    for (int i = 0; i <= borrowedMovies.size(); i++) {
        if (borrowedMovies[i] == title) {
            borrowedMovies.erase(borrowedMovies.begin() + i - 1);
            return true;
        }
    } 
    return false; 
}

string Customer::toCustomerString() const { 
    return to_string(customerID) + " " + lastName + " " + firstName;
}
