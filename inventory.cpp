#include "inventory.h"

void Inventory::addMedia(Media *m) {
    string key = generateUniqueKey(m);
    hashTable.add(key, m);
}

Media *Inventory::getMedia(string title) { 
    return hashTable.findMovie(title);
}

bool Inventory::doesMediaExist(string title) { 
    return hashTable.findMovie(title) != nullptr;
}

int Inventory::indexOfMedia(string title) { 
    return 0; 
}

void Inventory::printCustomerList() {
    for(int i = 0; i < customers.size(); i++) {
        cout << customers[i].toCustomerString() << endl;
    }
}

void Inventory::printMediaList() { 
    cout << hashTable.getAllMediaInfo();
}

string Inventory::generateUniqueKey(Media *m) { 
    string key = m->toMediaString();
    return key;
}


