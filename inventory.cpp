#include "inventory.h"

void Inventory::addMedia(Media *m) {
  string key = generateUniqueKey(m);
  hashTable.add(key, m);
}

Media *Inventory::getMedia(Media *m) { 
    string key = generateUniqueKey(m);
    return hashTable.findMovie(key);
}

bool Inventory::doesMediaExist(Media *m) {
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

bool Inventory::borrowMedia(Media* m) {
  // you can only borrow a movie if the stock > 0
  if (m->getStock() > 0) {
    m->decrementStock();
    return true;
  }
  return false;
}

bool Inventory::returnMedia(Media* m) {
  // returns are always welcome. 
  m->incrementStock();
  return true;
}