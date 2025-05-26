#include "ListHashTable.h"


ListHashTable::ListHashTable(size_t tabSize){
    _lists=new std::list<PTabRecord>[tabSize];
    _tabSize=tabSize;
    _curList=0;
}
ListHashTable::~ListHashTable(){
    for(size_t i=0;i<_tabSize;i++){
        for(auto rec:_lists[i]){
            delete rec;
        }
    }
    delete [] _lists;
}


bool ListHashTable::IsFull()const{
    bool res=false;
    try{
       PTabRecord a=new TabRecord(); 
       delete a;
    }
    catch (const char*){
        res=true;
    }
    return res;
}


PDatValue ListHashTable::FindRecord(const Key& key){}
void ListHashTable::InsRecord(const Key& key, PDatValue data){
    if(IsFull()){
        throw "no memory";
    }
    PDatValue tmp=FindRecord(key);
    if(tmp!=nullptr)
        throw "duplicate";
    _lists[_curList].push_front(new TabRecord(key, data));
    _dataCount++;
}
void ListHashTable::DelRecord(const Key& key){
    PDatValue tmp=FindRecord(key);
    if(tmp==nullptr)
        throw "record not found";
    _dataCount--;
    _lists[_curList].erase(_curElem);
}

bool ListHashTable::Reset(){
    _curList=0;
    _curElem=_lists[_curList].begin();
    return IsTabEnded();
}
bool ListHashTable::IsTabEnded()const {
    return (_curList>=_tabSize);
}
bool ListHashTable::GoNext(){
    if(!IsTabEnded()){
        bool flag=false;
        while(_lists[_curList].empty()){
            _curList++;
            flag=true;
            _curElem=_lists[_curList].begin();
        }
        if(!flag)
            _curElem++;
        
        if(_curElem==_lists[_curList].end()){
            _curList++;
            _curElem=_lists[_curList].begin();
        }
        

    }
    return IsTabEnded();

}

Key ListHashTable::GetKey() const{
    if(IsTabEnded())
        return "";
    return (*_curElem)->GetKey();
}
PDatValue ListHashTable::GetValuePtr()const {
    if(IsTabEnded())
        return nullptr;
    return (*_curElem)->GetData();
}