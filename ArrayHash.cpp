#include <iostream>
#include "ArrayHash.h"

// ArrayHash::ArrayHash(size_t size=100, size_t hashStep=7):HashTable(),_tabSize(size), _hashStep(hashStep){
//     _records=new PTabRecord[_tabSize];
//     for(size_t i=0;i<_tabSize;i++){
//         _records[i]=nullptr;
//     }
//     _mark=new TabRecord("", nullptr);

// }


bool ArrayHash::IsFull(){
    return _dataCount>=_tabSize;

}
PDatValue ArrayHash::FindRecord(const Key& key){
    _efficiency=0;
    _freePos=-1;
    PDatValue pVal=nullptr;
    _curPos=HashFunc(key)%_tabSize;
    for(size_t i=0;i<_tabSize;i++){
        _efficiency++;
        if(_records[_curPos]==nullptr)
            break;
        
        else{
            if(_records[_curPos]==_mark){
                if(_freePos==-1)
                _freePos=_curPos;
            }
            else{
                if(_records[_curPos]->GetKey()==key){
                    pVal=_records[_curPos]->GetData();
                    break;
                }
            }
            _curPos=GetNextPos(_curPos);
        }
    }
    return pVal;

}

void ArrayHash::InsRecord(const Key& key, PDatValue data){
    if(IsFull())
        throw "table is full";
    PDatValue pVal=FindRecord(key);
    if(pVal!=nullptr){
        throw "dublicate";
    }
    if(_freePos!=-1){
        _curPos=_freePos;
    }
    _records[_curPos]=new TabRecord(key, pVal);
    _dataCount++;
    




}
void ArrayHash::DelRecord(const Key& key){
    PDatValue PVal=FindRecord(key);
    if(PVal==nullptr)
        throw "record not found";
    else{
        delete _records[_curPos];
        _dataCount--;
        _records[_curPos]=_mark;
    }


}

bool ArrayHash::Reset(){
    _curPos=0;
    while(_curPos<_tabSize){
        if(_records[_curPos]!=nullptr && _records[_curPos]!=_mark){
            break;
        }
        _curPos++;
    }
    return IsTabEnded();

}
bool ArrayHash::IsTabEnded()const {
    return _curPos>=_tabSize;

}
bool ArrayHash::GoNext(){
    if(!IsTabEnded()){
        while(_curPos<_tabSize)
            if(_records[_curPos]!=nullptr && _records[_curPos]!=_mark)
                break;
            _curPos++;
    }
    return IsTabEnded();
}

Key ArrayHash::GetKey() const {
    return (_curPos>=_tabSize)?"":_records[_curPos]->GetKey();

}
PDatValue ArrayHash::GetValuePtr()const {
    return (_curPos>=_tabSize)?nullptr:_records[_curPos]->GetData();

}