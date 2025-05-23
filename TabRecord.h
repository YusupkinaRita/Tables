#pragma once
#include "DatValue.h"



using Key=std::string;

class TabRecord:public DatValue{
protected:
    PDatValue _data;
    Key _key;

public:
    TabRecord(Key key="", PDatValue data=nullptr){
        _key=key;
        _data=data;
    }
    void SetKey(Key key){
        _key=key;}
    Key GetKey()const{
        return _key;}
    void SetData(PDatValue data){
        _data=data;
    }
    PDatValue GetData()const{
        return _data;
    }

    virtual PDatValue GetCopy(){
        return _data->GetCopy(); 
    }
    virtual PDatValue GetRand(){
        return _data->GetRand(); 
    }
    TabRecord& operator=(const TabRecord& tr){
        _data= tr._data;
        _key=tr._key;
        return *this;
    }

    virtual bool operator==(const TabRecord& tr)const{
        return _key==tr._key;
    }
    virtual bool operator>(const TabRecord& tr)const{
        return _key>tr._key;
    }
    virtual bool operator<(const TabRecord& tr)const{
        return _key<tr._key;
    }

    friend class ScanTable;
    friend class ArrayTable;
    friend class SortTable;

    void Print(std::ostream &os)const override{
        os<<"data: "<<_data<<",  key: "<<_key<<std::endl;
        
    }

};