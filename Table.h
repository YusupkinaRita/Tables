#pragma once
#include <iostream>
#include "TabRecord.h"


class Table{
protected:
    size_t _dataCount;
    int _efficiency;

public:
    Table(){
    _dataCount=0;
    _efficiency=0;//эфективность операции
    }


    virtual ~Table(){};

    size_t GetDataCount()const{return _dataCount;};
    int GetEfficiency()const{return _efficiency;};
    bool IsEmpty()const{return _dataCount==0;}
    virtual bool IsFull()const =0;
    virtual Key Getkey() const=0;
    virtual PDatValue GetValue()const=0;


    //методы вставки, поиска и удаления
    virtual PDatValue Find(const Key& key)=0;
    virtual void InsRecord(const Key& key, PDatValue value)=0;
    virtual void DelRecord(const Key& key)=0;


    //навигация

    virtual bool Reset()=0;//сброс текущего положения на начальное положение
    virtual bool IsTabEnded()const =0;//проверить не завершена ли таблица
    virtual bool GoNext()=0;//переход на следующее положение



};