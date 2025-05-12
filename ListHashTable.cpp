#include "ListHashTable.h"


ListHashTable::ListHashTable(size_t tabSize){
    _lists=new std::forward_list<PTabRecord>[tabSize];
    _tabSize=tabSize;
    _curList=0;
}
ListHashTable::~ListHashTable(){
    for(size_t i=0;i<_tabSize;i++){
        for(auto rec:_lists[i]){
            delete rec;
        }
    }
    delete [] _lists;
}

PDatValue ListHashTable::FindRecord(const Key& key){}
void ListHashTable::InsRecord(const Key& key, PDatValue data){}
void ListHashTable::DelRecord(const Key& key){}

bool ListHashTable::Reset(){}
bool ListHashTable::IsTabEnded()const {}
bool ListHashTable::GoNext(){}

Key ListHashTable::GetKey() const{}
PDatValue ListHashTable::GetValuePtr()const {}