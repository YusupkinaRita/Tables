#include <iostream>
#include "TabRecord.h"

class TreeNode;
using PTreeNode=TreeNode*;

class TreeNode:public TabRecord{
protected:
    PTreeNode _pLeft;
    PTreeNode _pRight;

public:
    TreeNode(Key key="", PDatValue data=nullptr, PTreeNode pl=nullptr,PTreeNode pr=nullptr ):TabRecord(key, data){
        _pLeft=pl;
        _pRight=pr;

    }

    PTreeNode GetLeft()const{
        return _pLeft;
    }
    PTreeNode GetRight()const{
        return _pRight;
    }

    virtual PDatValue GetCopy(){
        PTreeNode copyTree= new TreeNode(_key, _data);
        return copyTree;
    }
    friend class TreeTable;
    friend class BalancedTreeTable;



};