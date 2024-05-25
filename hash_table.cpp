#include "hash_table.h"

HashTable::HashTable() {
    tableSize = 0;
}

bool HashTable::add(const string &key, Media *media) { 
    table[key] = {key, media};
    return true;
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

string HashTable::getAllMediaInfo() const {
    string result;
    for (const auto &entry : table) {
        result += entry.second.media->toMediaString() + "\n";
    }
    return result;
}
