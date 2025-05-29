#include <iostream>
#include "ArrayTable.h"
#include "TableTestKit.h"
#include "SortTable.h"
#include "Marks.h"


int main(){
    srand(time(NULL));
    ScanTable test_table=ScanTable(20000);
    //SortTable test_sort=SortTable(200);
    TableTestKit test=TableTestKit(test_table);
    Marks* mark_test=new Marks(5,5,5,5);
    test.GenBenchmarkTab(mark_test, "benchmarkscan.txt", 20000);
    //test.ShowTable();
    test.PrintMetrics(10000);






}