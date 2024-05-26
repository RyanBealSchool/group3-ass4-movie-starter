#include "inventory.h"

void Inventory::addMedia(Media *m) {
    Movie *movie = dynamic_cast<Movie*>(m);
    if (movie) {
        sortedMovies.push(*movie);
    }
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
    //cout << hashTable.getAllMediaInfo();
    hashTable.printAllMediaSorted();
}

string Inventory::generateUniqueKey(Media *m) { 
    string key = m->toMediaString();
    return key;
}


