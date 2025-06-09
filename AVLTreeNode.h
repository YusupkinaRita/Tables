#pragma once
#include "TabRecord.h"

class AVLTreeNode : public TabRecord {
protected:
    AVLTreeNode* _pLeft;
    AVLTreeNode* _pRight;
    int _height;
public:
    AVLTreeNode(const Key& key = "", PDatValue data = nullptr)
        : TabRecord(key, data), _pLeft(nullptr), _pRight(nullptr), _height(1) {}
    

    // PAVLNode GetLeft()const{
    //     return _pLeft;
    // }
    // PAVLNode GetRight()const{
    //     return _pRight;
    // }
    // int GetHeight()const{
    //     return _height;
    // }
    // void SetHeight(int height){
    //     _height=height;
    // }


    friend class AVLTreeTable;

};