#include "HashTable.h"


size_t HashTable::HashFunc(const Key& key){//за хорошую хэш функцию +
    size_t hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c; // djb2
    }
    return hash;
}