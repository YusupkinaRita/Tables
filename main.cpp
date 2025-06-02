#include <iostream>
#include "ArrayTable.h"
#include "TableTestKit.h"
#include "SortTable.h"
#include "Marks.h"
#include "ArrayHash.h"
#include "ListHashTable.h"


int main(){
    srand(time(NULL));
    Marks* mark_test=new Marks(5,5,5,5);

    ScanTable test_table=ScanTable(20000);
    TableTestKit test=TableTestKit(test_table);
    test.GenBenchmarkTab(mark_test, "benchmarkscan.txt", 20000);
    // test.ShowTable();
    // test.PrintMetrics(1000);



    SortTable sort_table = SortTable();
    sort_table=test_table;
    TableTestKit t=TableTestKit(sort_table);
    t.ShowTable();


    //TableTestKit test_sort=TableTestKit(sort_table);
    // test_sort.GenBenchmarkTab(mark_test, "benchmarksort.txt", 20000);
    //test_sort.PrintMetrics(1000);

    // ArrayHash xx=ArrayHash(20000);
    // TableTestKit test_hash=TableTestKit(xx);
    // test_hash.GenBenchmarkTab(mark_test, "benchmarkhash.txt", 20000);
    // test_hash.PrintMetrics(1000);
    
    // ListHashTable lh=ListHashTable(20000);
    // TableTestKit test_hashl=TableTestKit(lh);
    // test_hashl.GenBenchmarkTab(mark_test, "benchmarkhashlist.txt", 20000);
    // test_hashl.PrintMetrics(1000);
    


    






}