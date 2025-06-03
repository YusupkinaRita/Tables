#pragma once
#include "DatValue.h"
#include <sstream>



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
        TabRecord* copy=new TabRecord(_key, _data);
        return copy; 
    }
    virtual PDatValue GetRand(){
        return _data->GetRand(); 
    }
    std::string ToStr()override{
        std::string str=_key+ "|";
        str+=_data->ToStr();
        return str;
    }
    void Deserialise(std::string str)override{
        std::istringstream iss(str);

        std::getline(iss, _key, '|'); 
        std::string data_str;
        std::getline(iss, data_str);
        _data->Deserialise(data_str);

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