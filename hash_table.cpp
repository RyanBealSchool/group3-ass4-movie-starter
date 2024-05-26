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

void HashTable::printAllMediaSorted() const {
    auto compare = [](Media* m1, Media* m2) {
        Movie* movie1 = dynamic_cast<Movie*>(m1);
        Movie* movie2 = dynamic_cast<Movie*>(m2);
        if (movie1 && movie2) {
            return *movie1 < *movie2;
        }
        return false;
    };

    priority_queue<Media*, vector<Media*>, decltype(compare)> pq(compare);

    for (const auto &entry : table) {
        pq.push(entry.second.media);
    }

    while (!pq.empty()) {
        cout << pq.top()->toMediaString() << endl;
        pq.pop();
    }
}
