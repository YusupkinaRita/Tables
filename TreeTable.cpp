#include "TreeTable.h"
#include <algorithm>
#include <iomanip>



PDatValue TreeTable::FindRecord(const Key& key){
   _ppRef = &_pRoot;
    PTreeNode pNode = *_ppRef;
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
    if (*_ppRef != nullptr)
        throw "inserting into non-empty spot";
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
    _dataCount--;
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

void TreeTable::DeleteTreeTable(PTreeNode pNode) {
    if (pNode != nullptr) {
        DeleteTreeTable(pNode->GetLeft());
        DeleteTreeTable(pNode->GetRight());
        
        delete pNode;
    }
}
  
bool TreeTable::Reset() {
    while (!_stack.empty()) {
        _stack.pop();
    }
    _curPos = 0;
    PTreeNode pNode = _pRoot;
    while (pNode != nullptr) {
        _stack.push(pNode);
        pNode = pNode->GetLeft();
    }
    if (!_stack.empty()) {
        _pCur = _stack.top();
    } else {
        _pCur = nullptr;
    }
    return IsTabEnded();
}

bool TreeTable::IsTabEnded() const{
    return _curPos >= _dataCount;
} 


bool TreeTable::GoNext(){
    if(!IsTabEnded() && _pCur != nullptr){
        PTreeNode curNode = _stack.top();
        _stack.pop();
        
        PTreeNode pNode = curNode->GetRight();
        while(pNode != nullptr){
            _stack.push(pNode);
            _pCur = pNode;
            pNode = pNode->GetLeft();
        }
        _pCur = !_stack.empty() ? _stack.top() : nullptr;
        _curPos++;
    }
    return IsTabEnded();
}

void TreeTable::PrintTreeTable(std::ostream &os, PTreeNode pNode){
    if(pNode != nullptr){
        PrintTreeTable(os, pNode->GetLeft());
        pNode->Print(os);
        std::cout << std::endl;
        PrintTreeTable(os, pNode->GetRight());
    }
}

void TreeTable::DrawTreeTable(PTreeNode root, size_t lvl) {
    if (root == nullptr) 
        return;
    DrawTreeTable(root->GetRight(), lvl + 1);

    for (size_t i = 0; i < lvl * 8; ++i)
        std::cout << ' ';

    std::cout << root->GetKey() << std::endl;

    DrawTreeTable(root->GetLeft(), lvl + 1);
}

void TreeTable::PutValues(PTreeNode pNode, size_t lvl){
    if(pNode != nullptr){ 
        PutValues(pNode ->GetLeft(), lvl+1);
        _k.push_back(pNode->GetKey());
        _t.push_back(lvl);
        PutValues(pNode ->GetRight(), lvl+1);
    }
}

void TreeTable::Draw(){
    std::cout << "Tree " << std::endl;
    DrawTreeTable(_pRoot, 0);
}

void TreeTable::Show() {
    _k.clear();
    _t.clear();
    PutValues(_pRoot, 0);

    if (_k.empty()) {
        std::cout << "Tree is empty.\n";
        return;
    }

    size_t maxl = 0;
    for (auto lvl : _t) {
        if (lvl > maxl)
            maxl = lvl;
    }

    std::cout << "\nTree table visualisation:\n";

    for (size_t level = 0; level <= maxl; ++level) {
        size_t prevIndex = 0;

        for (size_t i = 0; i < _k.size(); ++i) {
            if (_t[i] == level) {
                size_t spaces = 2 * (i - prevIndex);
                for (size_t s = 0; s < spaces; ++s)
                    std::cout << ' ';

                std::cout << std::setw(16) << std::left << _k[i];

                prevIndex = i + 1;
            }
        }
        std::cout << std::endl;
    }
}


