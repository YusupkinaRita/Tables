#pragma once
#include "Table.h"
#include "AVLTreeNode.h"
#include <stack>
#include <vector>


using PAVLNode = AVLTreeNode*;
class AVLTreeTable : public Table {
protected:
    PAVLNode _pRoot;
    PAVLNode _pCur;
    size_t _curPos;
    std::stack<PAVLNode> _stack;
    std::vector<std::string> _k;
    std::vector<size_t> _t;

    void DeleteTreeTable(PAVLNode node);
    void PrintTreeTable(std::ostream& os, PAVLNode node);
    void DrawTreeTable(PAVLNode node, size_t lvl);
    void PutValues(PAVLNode node, size_t level);

    //методы балансировки
    int BalanceFactor(PAVLNode node);
    void UpdateHeight(PAVLNode node);
    PAVLNode RotateRight(PAVLNode y);
    PAVLNode RotateLeft(PAVLNode x);
    PAVLNode Balance(PAVLNode node);
    int GetHeight(PAVLNode node);

    PAVLNode Insert(PAVLNode node, const Key& key, PDatValue data);
    PAVLNode Delete(PAVLNode node, const Key& key);
    PAVLNode Find(PAVLNode node, const Key& key);
    PAVLNode FindMin(PAVLNode node);

public:
    AVLTreeTable() {
        _pRoot = nullptr;
        _pCur = nullptr;
        _curPos = 0;
    }

    ~AVLTreeTable() {
        DeleteTreeTable(_pRoot);
    }

    bool IsFull() const override {
        try {
            PAVLNode tmp = new AVLTreeNode();
            delete tmp;
        } catch (...) {
            return true;
        }
        return false;
    }

    PDatValue FindRecord(const Key& key) override;
    void InsRecord(const Key& key, PDatValue value) override;
    void DelRecord(const Key& key) override;

    bool Reset() override;
    bool IsTabEnded() const override;
    bool GoNext() override;

    Key GetKey() const override;
    PDatValue GetValuePtr() const override;

    void Draw(); 
    void Show(); 

    friend std::ostream& operator<<(std::ostream& os, AVLTreeTable& table) {
        std::cout << "Print AVL Tree Table: " << std::endl;
        table.PrintTreeTable(os, table._pRoot);
        return os;
    }

    
};


