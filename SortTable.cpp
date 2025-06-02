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
    PTabRecord* pData=_records;
    PTabRecord* pBuf=new PTabRecord[_dataCount];
    PTabRecord* pTmp=pBuf;

    MergeSorter(pData, pBuf,_dataCount);

    if(pData==pTmp){
        for(size_t i=0;i<_dataCount;i++){
            pBuf[i]=pData[i];
        }

    }

    delete[] pTmp;

}
void SortTable::MergeSorter(PTabRecord* &pData, PTabRecord* &pBuf, size_t count){
    size_t n1=(count +1)/2;
    size_t n2=count-n1;

    if(count>2){
        PTabRecord* pData2=pData+n1;
        PTabRecord* pBuf2=pBuf+n1;
        MergeSorter(pData, pBuf, n1);
        MergeSorter(pData2, pBuf2, n2);
    }

    MergeData(pData, pBuf, n1, n2);


}
void SortTable::MergeData(PTabRecord* &pData, PTabRecord* &pBuf, size_t n1, size_t n2){
    size_t i=0 , i1=0, i2=0;
    PTabRecord* pDat1=pData, *pDat2=pData+n1;

    while(i1<n1 && i2<n2){
        if(pDat1[i1]->_key < pDat2[i2]->_key){
            pBuf[i++]=pDat1[i1++];
        }
        else{
            pBuf[i++]=pDat2[i2++];
        }
    }

    while(i1<n1){
        pBuf[i++]=pDat1[i1++];;
    }

    while(i2<n2){
        pBuf[i++]=pDat2[i2++];;
    }

    pData=pBuf;
    pBuf=pDat1;
    _efficiency+=n1+n2;

}

void SortTable::QuickSort(PTabRecord* pMem, size_t count){
    size_t pivot;
    size_t n1, n2;
    if(count>1){
        QuickSplit(pMem, count, pivot);
        n1=pivot+1;
        n2=count-n1;
        QuickSort(pMem,n1-1);
        QuickSort(pMem+n1,n2);
    }


}
void SortTable::QuickSplit(PTabRecord* pMem, size_t size, size_t& pivot){
    PTabRecord pPivot=pMem[0];
    PTabRecord pTmp;
    size_t i1=1, i2=size-1;
    while(i1<=i2){
        while(i1<size && !(pMem[i1]->_key > pPivot->_key)){
            i1++;
        }

        while(pMem[i1]->_key > pPivot->_key){
            i2--;
        }
        if(i1<i2){
            pTmp=pMem[i1];
            pMem[i1]=pMem[i2];
            pMem[i2]=pTmp;
        }
    }
    _efficiency+=size;
    pivot=i2;
    pMem[0]=pMem[i2];
    pMem[i2]=pPivot;

}

PDatValue SortTable::FindRecord(const Key& key){
    if(IsEmpty())
        return nullptr;
    _efficiency=0;
    int left = 0;
    int right = this->GetDataCount() - 1;
    while (left <= right) {
        _efficiency++;
        
        _curPos = left + (right - left) / 2;
        Key midKey = _records[_curPos]->GetKey(); 

        if (midKey == key) {
            return _records[_curPos]->GetData(); 
        } else if (midKey < key) {
            left = _curPos + 1;
        } else {
            right = _curPos - 1;
        }

    }
    if (_records[_curPos]->GetKey() < key){
        _curPos++;
    }
    
    return nullptr;

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
    if(tmp==nullptr)
        throw "no element with this key";
    if(tmp!=nullptr){
        for(size_t i=_curPos;i<_dataCount-1;i++){
            _records[i]=_records[i+1];
            _efficiency++;

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