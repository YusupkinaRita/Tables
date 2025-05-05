#pragma once
#include "HashTable.h"
#include <forward_list>
#include "ArrayHash.h"



class ListHashTable:public HashTable{
private:
    size_t _tabSize;
    size_t _curList;
    std::forward_list<PTabRecord>* _lists;
public:
    ListHashTable(size_t tabSize);
    ~ListHashTable();

    bool IsFull(){
        return false;
    }
    PDatValue FindRecord(const Key& key)override;
    void InsRecord(const Key& key, PDatValue data)override;
    void DelRecord(const Key& key)override;

    bool Reset()override;
    bool IsTabEnded()const override;
    bool GoNext()override;

    Key GetKey() const override;
    PDatValue GetValuePtr()const override;

};