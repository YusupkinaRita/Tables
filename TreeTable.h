#include "Table.h"
#include "TreeNode.h"
#include <stack>
#include <string>
#include <vector>

class TreeTable:public Table{
protected:
    PTreeNode _pRoot;
    PTreeNode _pCur;
    PTreeNode* _ppRef;//
    std::stack<PTreeNode> _stack;
    size_t _curPos;
    void PrintTreeTable(std::ostream& os, PTreeNode pNode);
    void DrawTreeTable(PTreeNode root,size_t lvl);
    void DeleteTreeTable(PTreeNode pNode); 
    //поля для отрисовки
    std::vector<std::string> _k;
    std::vector<size_t> _t;
    //size_t pos;
    void PutValues(PTreeNode pNode, size_t level );
public:
    TreeTable():Table(){
        _pRoot=nullptr;
        _ppRef=nullptr;
        _pCur=nullptr;
        _curPos=0;
    }

    ~TreeTable(){
        DeleteTreeTable(_pRoot);
    }

    bool IsFull()const override{
        try{
        PTreeNode tmp=new TreeNode();
        delete tmp;
        } 
        catch(const char* exc){
            return true;

        }
        return false;

    }

    PDatValue FindRecord(const Key& key)override;
    void InsRecord(const Key& key, PDatValue value)override;
    void DelRecord(const Key& key) override;



    bool Reset() override;
    bool IsTabEnded()const override;
    bool GoNext()override;

    Key GetKey() const override;
    PDatValue GetValuePtr()const override;

    void Draw();
    void Show();

    friend std::ostream& operator <<(std::ostream &os, TreeTable &table){
        std::cout << "Print table: " << std::endl;
        table.PrintTreeTable(os, table._pRoot);
        return os;
    }




};