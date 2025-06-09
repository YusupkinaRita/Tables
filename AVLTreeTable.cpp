#include "AVLTreeTable.h"
#include <iomanip>



void AVLTreeTable::DeleteTreeTable(PAVLNode node){
    if (node != nullptr) {
        DeleteTreeTable(node->_pLeft);
        DeleteTreeTable(node->_pRight);
        
        delete node;
    }
}
void AVLTreeTable::PrintTreeTable(std::ostream &os, PAVLNode pNode){
    if(pNode != nullptr){
        PrintTreeTable(os, pNode->_pLeft);
        pNode->Print(os);
        std::cout << std::endl;
        PrintTreeTable(os, pNode->_pRight);
    }
}
void AVLTreeTable::DrawTreeTable(PAVLNode root, size_t lvl) {
    if (root == nullptr) 
        return;
    DrawTreeTable(root->_pRight, lvl + 1);

    for (size_t i = 0; i < lvl * 8; ++i)
        std::cout << ' ';

    std::cout << root->GetKey() << std::endl;

    DrawTreeTable(root->_pLeft, lvl + 1);
}

void AVLTreeTable::PutValues(PAVLNode pNode, size_t lvl){
    if(pNode != nullptr){ 
        PutValues(pNode->_pLeft, lvl+1);
        _k.push_back(pNode->GetKey());
        _t.push_back(lvl);
        PutValues(pNode->_pRight, lvl+1);
    }
}


int AVLTreeTable::GetHeight(PAVLNode node) {
    return node ? node->_height : 0;
}

int AVLTreeTable::BalanceFactor(PAVLNode node) {
    return GetHeight(node->_pRight) - GetHeight(node->_pLeft);
}

void AVLTreeTable::UpdateHeight(PAVLNode node) {
    node->_height = 1 + std::max(GetHeight(node->_pLeft), GetHeight(node->_pRight));
}
PAVLNode AVLTreeTable::RotateRight(PAVLNode node){
    PAVLNode x = node->_pLeft;
    PAVLNode tmp = x->_pRight;

    x->_pRight = node;
    node->_pLeft = tmp;

    UpdateHeight(node);
    UpdateHeight(x);
    return x;
}
PAVLNode AVLTreeTable::RotateLeft(PAVLNode node){
    PAVLNode x = node->_pRight;
    PAVLNode tmp = x->_pLeft;

    x->_pLeft = node;
    node->_pRight = tmp;

    UpdateHeight(node);
    UpdateHeight(x);
    return x;
}
PAVLNode AVLTreeTable::Balance(PAVLNode node){
    UpdateHeight(node);
    int balance = BalanceFactor(node);

    // перевес вправо
    if (balance > 1) {
        if (BalanceFactor(node->_pRight) < 0)
            node->_pRight = RotateRight(node->_pRight); 
        return RotateLeft(node); 
    }

    // перевес влево
    if (balance < -1) {
        if (BalanceFactor(node->_pLeft) > 0)
            node->_pLeft = RotateLeft(node->_pLeft); 
        return RotateRight(node); 
    }

    return node;
}



bool AVLTreeTable::Reset() {
    while (!_stack.empty()) {
        _stack.pop();
    }
    _curPos = 0;
    PAVLNode pNode = _pRoot;
    while (pNode != nullptr) {
        _stack.push(pNode);
        pNode = pNode->_pLeft;
    }
    if (!_stack.empty()) {
        _pCur = _stack.top();
    } else {
        _pCur = nullptr;
    }
    return IsTabEnded();
}

bool AVLTreeTable::IsTabEnded() const {
    return _curPos >= _dataCount;
}
bool AVLTreeTable::GoNext() {
    if (!IsTabEnded() && _pCur != nullptr) {
        PAVLNode curNode = _stack.top();
        _stack.pop();

        PAVLNode pNode = curNode->_pRight;
        while (pNode != nullptr) {
            _stack.push(pNode);
            pNode = pNode->_pLeft;
        }
        _pCur = !_stack.empty() ? _stack.top() : nullptr;
        _curPos++;
    }
    return IsTabEnded();
}


Key AVLTreeTable::GetKey() const {
    if (_pCur == nullptr)
        return "";
    return _pCur->_key;
}
PDatValue AVLTreeTable::GetValuePtr() const {
    if (_pCur == nullptr)
        return nullptr;
    return _pCur->_data;
}

PAVLNode AVLTreeTable::Insert(PAVLNode node, const Key& key, PDatValue data) {
    if (node == nullptr) {
        //новый узел, если достигли пустого места
        return new AVLTreeNode(key, data);
    }
    if (key < node->_key) {
        node->_pLeft = Insert(node->_pLeft, key, data);
    } else if (key > node->_key) {
        node->_pRight = Insert(node->_pRight, key, data);
    } else {
        node->_data = data;
        return node;
    }

    // балансируем поддерево с корнем node после вставки
    return Balance(node);
}

void AVLTreeTable::InsRecord(const Key& key, PDatValue value) {
    _pRoot = Insert(_pRoot, key, value);
    _dataCount++;
}


PAVLNode AVLTreeTable::Find(PAVLNode node, const Key& key) {
    _efficiency++;
    
    if (node == nullptr) {
        return nullptr;
    }
    if (key == node->_key) {
        return node;
    } 
    else if (key < node->_key) {
        return Find(node->_pLeft, key);
    } 
    else {
        return Find(node->_pRight, key);
    }
}

PDatValue AVLTreeTable::FindRecord(const Key& key) {
    _efficiency = 0;  
    PAVLNode node = Find(_pRoot, key);
    if (node == nullptr)
        return nullptr;
    return node->_data;
}

PAVLNode AVLTreeTable::FindMin(PAVLNode node) {
    if (node == nullptr) {
        return nullptr;
    }
    while (node->_pLeft != nullptr) {
        node = node->_pLeft;
    }

    return node;
}

PAVLNode AVLTreeTable::Delete(PAVLNode node, const Key& key) {
    if (node == nullptr) {
        throw "Key not found";
    }

    if (key < node->_key) {
        node->_pLeft = Delete(node->_pLeft, key);
    } else if (key > node->_key) {
        node->_pRight = Delete(node->_pRight, key);
    } else {
        
        //Узел без детей
        if (node->_pLeft == nullptr && node->_pRight == nullptr) {
            delete node;
            return nullptr;
        }
        //Узел с одним ребёнком
        else if (node->_pLeft == nullptr) {
            PAVLNode tmp = node->_pRight;
            delete node;
            return tmp;
        }
        else if (node->_pRight == nullptr) {
            PAVLNode tmp = node->_pLeft;
            delete node;
            return tmp;
        }
        //Узел с двумя детьми
        else {
            // Найдём минимальный узел в правом поддереве
            PAVLNode minRight = FindMin(node->_pRight);
            // Заменяем данные текущего узла на его
            node->_key = minRight->GetKey();
            node->SetData(minRight->GetData()->GetCopy());
            // Удаляем из правого поддерева рекурсивно
            node->_pRight = Delete(node->_pRight, minRight->_key);
        }
    }

    return Balance(node);
}
void AVLTreeTable::DelRecord(const Key& key) {
    _pRoot = Delete(_pRoot, key);
    _dataCount--;  // Уменьшаем счётчик элементов
}

void AVLTreeTable::Draw(){
    std::cout << "Tree " << std::endl;
    DrawTreeTable(_pRoot, 0);
}


void AVLTreeTable::Show() {
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