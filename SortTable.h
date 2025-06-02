#pragma once
#include <iostream>
#include "ScanTable.h"

enum SortMethod{Insert, Merge, Quick};

class SortTable:public ScanTable{
private:
protected:
    SortMethod _sortMethod=SortMethod::Quick;
    void SortData();
    void InsertSort(PTabRecord* pMem, size_t count);

    void MergeSort(PTabRecord* pMem, size_t count);
    void MergeSorter(PTabRecord* &pData, PTabRecord* &pBuf, size_t count);
    void MergeData(PTabRecord* &pData, PTabRecord* &pBuf, size_t n1, size_t n2);

    void QuickSort(PTabRecord* pMem, size_t count);
    void QuickSplit(PTabRecord* pMem, size_t size, size_t& pivot);

public:
    SortTable(size_t tabSize=25):ScanTable(tabSize){}
    // SortTable(const ScanTable& st):ScanTable(st){
    //     *this=st;
    // }
    SortTable& operator=(const ScanTable& st);


    void SetSortMethod(SortMethod sortMethod){
        _sortMethod=sortMethod;
    }

    SortMethod GetSortMethod()const{
        return _sortMethod;
    }


    virtual PDatValue FindRecord(const Key& key);
    virtual void InsRecord(const Key& key, PDatValue value);
    virtual void DelRecord(const Key& key);



};