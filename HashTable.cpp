#include "HashTable.h"


size_t HashTable::HashFunc(const Key& key){
    size_t index=0;
    size_t size=key.size();
    for(size_t i=0;i<size;i++){
        index+=(size_t)key[i];//за самую быструю хэш функцию плюсик
    }
    return index;
}