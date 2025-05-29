#include <iostream>
#include "ArrayTable.h"
#include "TableTestKit.h"
#include "SortTable.h"
#include "Marks.h"
#include "ArrayHash.h"


int main(){
    srand(time(NULL));
    Marks* mark_test=new Marks(5,5,5,5);

    // ScanTable test_table=ScanTable(20000);
    // TableTestKit test=TableTestKit(test_table);
    // test.GenBenchmarkTab(mark_test, "benchmarkscan.txt", 20000);
    // test.ShowTable();
    // test.PrintMetrics(1000);



    SortTable sort_table=SortTable(20000);
    // sort_table.InsRecord("v", mark_test);
    TableTestKit test_sort=TableTestKit(sort_table);
    test_sort.GenBenchmarkTab(mark_test, "benchmarksort.txt", 10000);
    test_sort.ShowTable();
    test_sort.PrintMetrics(1000);

    ArrayHash xx=ArrayHash();

    






}