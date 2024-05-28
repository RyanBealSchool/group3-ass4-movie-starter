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
    for (int i = 0; i <= history.size(); i++) {
        if (history[i].second == title) {
            return true;
        }
    } 
    return false; 
}

bool Customer::borrowMovie(string title) {

    history.push_back(make_pair('B', title));
    return true;
}

bool Customer::returnMovie(string title) {
    for(int i = 0; i < history.size(); i++)
    {
        if(history[i].second == title)
        {
            history.push_back(make_pair('R', title));
            return true;
        }
    }
    return false; 
}

string Customer::toCustomerString() const { 
    return to_string(customerID) + " " + lastName + " " + firstName;
}

void Customer::printHistory()
{
    for(int i = 0; i < history.size(); i++)
    {
        cout << history[i].first << " " << history[i].second << endl;
    }
}