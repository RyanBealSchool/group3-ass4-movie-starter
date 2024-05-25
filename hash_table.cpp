#include "hash_table.h"

HashTable::HashTable() {
    tableSize = 0;
}

bool HashTable::add(const string &key, Media *media) { 
    table[key] = {key, media};
}

Media *HashTable::findMovie(string key) { 
    auto it = table.find(key);
    if (it != table.end()) {
        return it->second.media;
    }
    return nullptr;
}

int HashTable::hashFunction(int key) { 
    return key % static_cast<int>(table.bucket_count()); 
}

int HashTable::getTableSize() { 
    return table.size();
}
