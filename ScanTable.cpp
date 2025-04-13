#include "ScanTable.h"


PDatValue ScanTable::FindRecord(const Key& key){
    if(IsEmpty())
        throw "table is empty";
    Reset();
    PDatValue res;
    bool x=0;
    while(x!=1){
        if (GetKey(Current)==key)
            return GetValuePtr(Current);
        x=GoNext();
        _efficiency++;
    }
    std::cout<<"the key is not in the table"<<std::endl;
        return 0;

}
void ScanTable::InsRecord(const Key& key, PDatValue value){
    if(IsFull())
        throw "table is full";
    else{
        _records[_dataCount]=new TabRecord(key, value);
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