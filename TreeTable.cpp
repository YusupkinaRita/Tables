#include "TreeTable.h"




PDatValue TreeTable::FindRecord(const Key& key){
    PTreeNode pNode=_pRoot;
    _ppRef=&pNode;
    _efficiency=0;
    while(pNode!=nullptr){
        _efficiency++;
        if(pNode->_key==key)break;
        if(pNode->_key<key)
            _ppRef=&(pNode->_pRight);
        else  
            _ppRef=&(pNode->_pLeft);  

        pNode=*_ppRef;
    }
    return pNode==nullptr? nullptr:pNode->_data;


}
void TreeTable::InsRecord(const Key& key, PDatValue value){
    if(IsFull())
        throw "tree is full";
    if(FindRecord(key)!=nullptr)
        throw "dublicate";

    _dataCount++;
    *_ppRef=new TreeNode(key,value);
    
}
void TreeTable::DelRecord(const Key& key){
    if(FindRecord(key)==nullptr)
        throw "no element";
    PTreeNode pNode=*_ppRef;
    if(pNode->_pRight==nullptr)
        *_ppRef=pNode->_pLeft;
    else{
        if(pNode->_pLeft==nullptr)
            *_ppRef=pNode->_pRight; 
        else{
            PTreeNode pN=pNode->_pLeft;
            PTreeNode* ppR=&pNode->_pLeft;
            while(pN->_pRight){
                ppR=&pN->_pRight;
                pN=*ppR;

            }
            pNode->_data=pN->_data;
            pNode->_key=pN->_key;
            pNode=pN;
            *ppR=pN->_pLeft;

        }
    }
    delete pNode;
}


Key TreeTable::GetKey() const{
    if(_pCur==nullptr)
        return "";
    else
        return _pCur->_key;
}
PDatValue TreeTable::GetValuePtr()const {
    if(_pCur==nullptr)
        return nullptr;
    else
        return _pCur->_data;
}