#include <iostream>
#include "DatValue.h"
#include <cstdint>


class Marks:public DatValue{
private:
    uint16_t _math;
    uint16_t _cs;
    uint16_t _eng;
    uint16_t _phys;

public:
    Marks(uint16_t math, uint16_t cs, uint16_t eng, uint16_t phys){
        _math=math;
        _cs=cs;
        _eng=eng; 
        _phys=phys;
    }
    Marks(){
        _math=0;
        _cs=0;
        _eng=0; 
        _phys=0;
    }

    void Print(std::ostream &os)const override{
        os<<"math mark :"<<_math<<" ";
        os<<"cs mark :"<<_cs<<" ";
        os<<"eng mark :"<<_eng<<" ";
        os<<"phys mark :"<<_phys<<std::endl;
    }

    Marks* GetCopy() override{
        Marks* copy=new Marks(_math, _cs, _eng, _phys);
        return copy;

    }
    Marks* GetRand() override{
        uint16_t math=2+rand()%4;
        uint16_t cs=2+rand()%4;
        uint16_t eng=2+rand()%4;
        uint16_t phys=2+rand()%4;
        Marks* tmp=new Marks(math, cs, eng, phys);
        return tmp;

    }


    




};