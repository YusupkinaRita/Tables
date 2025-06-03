#pragma once
#include "HashTable.h"
#include <forward_list>
#include "ArrayHash.h"
#include <list>




class ListHashTable:public HashTable{
private:
    size_t _tabSize;
    size_t _curList;
    std::list<PTabRecord>* _lists;
    size_t _curPos;//current position in list
    std::list<PTabRecord>::iterator _curElem;
public:
    ListHashTable(size_t tabSize);
    ~ListHashTable();

    bool IsFull()const override;
    PDatValue FindRecord(const Key& key)override;
    void InsRecord(const Key& key, PDatValue data)override;
    void DelRecord(const Key& key)override;

    bool Reset()override;
    bool IsTabEnded()const override;
    bool GoNext()override;

    Key GetKey() const override;
    PDatValue GetValuePtr()const override;
    size_t GetMaxList();

};