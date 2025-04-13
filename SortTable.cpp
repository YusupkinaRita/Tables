#include "SortTable.h"


void SortTable::SortData(){
    _efficiency=0;
    switch(_sortMethod){
        case SortMethod::Insert:
            InsertSort(_records, _dataCount);break;
        case SortMethod::Merge:
            MergeSort(_records, _dataCount);break;
        case SortMethod::Quick:
            QuickSort(_records, _dataCount);break;

        default:
            throw "unavailible sort method";
    }

}
void SortTable::InsertSort(PTabRecord* pMem, size_t count){
    PTabRecord tmp;
    _efficiency=_dataCount;
    for(int i=1, j;i<_dataCount;i++){
        tmp=_records[i];
        for(j=i-1;j>-1;j--){
            if(_records[j]->_key>tmp->_key){
                _records[j+1]=_records[j];
                _efficiency++;
            }
            else{
                break;
            }

        }
        _records[j+1]=tmp;
    }

}

void SortTable::MergeSort(PTabRecord* pMem, size_t count){

}
void SortTable::MergeSorter(PTabRecord* &pData, PTabRecord* &pBuf, size_t count){

}
void SortTable::MergeData(PTabRecord* &pData, PTabRecord* &pBuf, size_t n1, size_t n2){

}

void SortTable::QuickSort(PTabRecord* pMem, size_t count){

}
void SortTable::QuickSplit(PTabRecord* pMem, size_t size, size_t pivot){

}

PDatValue SortTable::FindRecord(const Key& key){


//не забудь эфишенси увеличивать, вроде надо
}
void SortTable::InsRecord(const Key& key, PDatValue value){
    if(IsFull())
        throw "table is full";


    PDatValue tmp=FindRecord(key);
    for(size_t i=_dataCount;i>_curPos;i--){
        _records[i]=_records[i-1];
    }
    _records[_curPos]=new TabRecord(key, value);
    _dataCount++;
    _curPos=0;
}
void SortTable::DelRecord(const Key& key){
    if(IsEmpty())
        throw "table is empty";

    PDatValue tmp=FindRecord(key);
    if(tmp!=nullptr){
        for(size_t i=_curPos;i<_dataCount-1;i++){
            _records[i]=_records[i+1];

        }
        _records[_dataCount]=nullptr;
        delete tmp;
        _dataCount--;
        _curPos=0;
    }

}


SortTable& SortTable::operator=(const ScanTable& st){
        if(_records!=nullptr){
            for(size_t i=0;i<_dataCount;i++){
                delete _records[i];
            }
            delete [] _records;
        }
        _tabSize=st._tabSize;
        _dataCount=st.GetDataCount();
        _records=new PTabRecord[_tabSize];
        for(size_t i=0;i<_dataCount;i++){
            _records[i]=(PTabRecord)st._records[i]->GetCopy();
        }
        SortData();
        _curPos=0;

        return *this;
        
    }