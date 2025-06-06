#pragma once
#include <iostream>

class DatValue{

protected:
    virtual void Print(std::ostream &os)const=0;


public:
    DatValue(){}
    virtual DatValue* GetCopy()=0;
    virtual DatValue* GetRand()=0;
    virtual std::string ToStr()=0;
    virtual void Deserialise(std::string str)=0;

    friend std::ostream& operator<<(std::ostream &os, const DatValue& dv){
        if(&dv!=nullptr){
            dv.Print(os);
        }

        return os;
    }


};

//typedef DatValue* PDatValue;
using PDatValue=DatValue*;