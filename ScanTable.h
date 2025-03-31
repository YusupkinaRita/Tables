#pragma once
#include "ArrayTable.h"



class ScanTable:public ArrayTable{
public:
    ScanTable(size_t size=25):ArrayTable(size){};

    virtual PDatValue FindRecord(const Key& key);
    virtual void InsRecord(const Key& key, PDatValue value);
    virtual void DelRecord(const Key& key);

};