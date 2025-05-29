#include <iostream>
#include "HashTable.h"
#include "ArrayTable.h"


class ArrayHash:public HashTable{
protected:
    PTabRecord* _records;
    size_t _tabSize;
    size_t _curPos;
    long _freePos;
    size_t _hashStep;
    PTabRecord _mark;//отличать удаленные записи от тех, которые не были никогда заняты
    size_t GetNextPos(size_t pos){
        return (pos+_hashStep)%_tabSize;
    }
public:
    ArrayHash(size_t size=100, size_t hashStep=7);//про шаг нужно посмотреть, будут вопросы по нему
    ~ArrayHash(){
        for(size_t i=0; i<_dataCount;i++){
            if(_records[i]!=nullptr)
                delete _records[i];
        }

        delete [] _records;
        delete _mark;
    }

    bool IsFull()const;
    PDatValue FindRecord(const Key& key)override;
    void InsRecord(const Key& key, PDatValue data)override;
    void DelRecord(const Key& key)override;

    bool Reset()override;
    bool IsTabEnded()const override;
    bool GoNext()override;

    Key GetKey() const override;
    PDatValue GetValuePtr()const override;

    

};