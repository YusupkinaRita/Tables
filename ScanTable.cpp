#include "ScanTable.h"


PDatValue ScanTable::FindRecord(const Key& key){

}
void ScanTable::InsRecord(const Key& key, PDatValue value){
    if(IsFull())
        throw "table is full";
    else{
        //_records[_dataCount]=new TabRecord(key, value);//нужно override print прям тут
        _dataCount++;
    }

}
void ScanTable::DelRecord(const Key& key){
    PDatValue tmp=FindRecord(key);
    if(tmp==nullptr)
        throw "no element with this key";
    else{
        _records[_curPos]=_records[_dataCount-1];
        _dataCount--;
    }
}