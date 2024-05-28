#include "inventory.h"

void Inventory::addMedia(Media *m) {
  string key = generateUniqueKey(m);
  hashTable.add(key, m);
}

Media *Inventory::getMedia(Media *m) { 
    //return hashTable.findMovie(m->toMediaString()); 
    string key = generateUniqueKey(m);
    return hashTable.findMovie(key);
}

bool Inventory::doesMediaExist(Media *m) {
    //return hashTable.findMovie(m->toMediaString()) != nullptr;
    string key = generateUniqueKey(m);
    return hashTable.findMovie(key) != nullptr;
}

int Inventory::indexOfMedia(Media *m) { return 0; }

void Inventory::printCustomerList() {
  for (int i = 0; i < customers.size(); i++) {
    cout << customers[i].toCustomerString() << endl;
  }
}

void Inventory::printMediaList() { 
    //cout << hashTable.getAllMediaInfo();
    hashTable.printAllMediaSorted();
}

string Inventory::generateUniqueKey(Media *m) {
  string key = m->getMediaID();
  return key;
}