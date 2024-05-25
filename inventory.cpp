#include "inventory.h"

void Inventory::addMedia(Media *m) {
    
}

Media *Inventory::getMedia(string title) { 
    return nullptr; 
}

bool Inventory::doesMediaExist(string title) { 
    return false; 
}

int Inventory::indexOfMedia(string title) { 
    return 0; 
}

void Inventory::printCustomerList() {
    for(int i = 0; i < customers.size(); i++) {
        cout << customers[i].toCustomerString() << endl;
    }
}

string Inventory::toMediaString() { 
    return string(); 
}
