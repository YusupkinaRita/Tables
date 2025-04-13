#pragma once 
#include "Table.h"
#include <iostream>


enum DataPos{First, Current, Last};
using PTabRecord=TabRecord*;

class ArrayTable:public Table{
protected:
    PTabRecord* _records;
    size_t _tabSize;
    size_t _curPos;
public:
    ArrayTable(size_t tabSize=25){
        _tabSize=tabSize;
        _records=new PTabRecord[_tabSize];
        for(size_t i=0; i<_tabSize;i++){
            _records[i]=nullptr;
        }
        _curPos=0;
    }
    ~ArrayTable(){
        for(size_t i=0; i<_dataCount;i++){
            delete _records[i];
        }

        delete [] _records;
    };


    //информационные методы
    virtual bool IsFull()const{
        return _dataCount>=_tabSize;
    }
    size_t GetTabSize()const{
        return _tabSize;
    }


    virtual Key GetKey()const{
        return GetKey(DataPos::Current);
    }

    virtual PDatValue GetValuePtr()const{
        return GetValuePtr(DataPos::Current);
    }

    virtual Key GetKey(DataPos position)const;
    virtual PDatValue GetValuePtr(DataPos position)const;


    virtual bool Reset();
    virtual bool IsTabEnded()const;
    virtual bool GoNext();

    bool SetCurrentPos(size_t pos);
    size_t GetCurrentPos()const{
        return _curPos;
    }







    friend class SortTable;

    

};