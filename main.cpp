#include <iostream>
#include "ArrayTable.h"
#include "TableTestKit.h"
#include "SortTable.h"
#include "Marks.h"
#include "ArrayHash.h"
#include "ListHashTable.h"
#include "TreeTable.h"
#include "AVLTreeTable.h"


int main(){
    srand(time(NULL));
    Marks* mark_test=new Marks(5,5,5,5);

    // ScanTable test_table=ScanTable(20000);
    // TableTestKit test=TableTestKit(test_table);
    // test.GenBenchmarkTab(mark_test, "benchmarkscan.txt", 20000);
    // test.ShowTable();



    // SortTable sort_table = SortTable(20000);
    // sort_table=test_table;
    // TableTestKit t=TableTestKit(sort_table);
    // t.PrintMetrics(1000);


    //TableTestKit test_sort=TableTestKit(sort_table);
    // test_sort.GenBenchmarkTab(mark_test, "benchmarksort.txt", 20000);
    //test_sort.PrintMetrics(1000);

    // ArrayHash xx=ArrayHash(20000);
    // TableTestKit test_hash=TableTestKit(xx);
    // test_hash.GenBenchmarkTab(mark_test, "benchmarkhash.txt", 10000);
    // test_hash.PrintMetrics(1000);


    
    // ListHashTable lh=ListHashTable(20000);
    // TableTestKit test_hashl=TableTestKit(lh);
    // test_hashl.GenBenchmarkTab(mark_test, "benchmarkhashlist.txt", 20000);
    // test_hashl.PrintMetrics(1000);
    // std::cout<<"maximum list size is "<<lh.GetMaxList()<<std::endl;
    
    // TreeTable treetab;
    // TableTestKit tree_test=TableTestKit(treetab);
    // tree_test.GenBenchmarkTab(mark_test, "treetable.txt",20000);
    // tree_test.PrintMetrics(1000);


    AVLTreeTable avltab;
    TableTestKit avl_test=TableTestKit(avltab);
    avl_test.GenBenchmarkTab(mark_test, "avltable.txt",20000);
    avl_test.PrintMetrics(1000);


    






}