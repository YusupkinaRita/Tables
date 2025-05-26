#include <iostream>
#include "ArrayTable.h"
#include "TableTestKit.h"
#include "SortTable.h"
#include "Marks.h"


int main(){
    ScanTable test_table=ScanTable();
    TableTestKit test=TableTestKit(test_table);
    Marks* mark_test=new Marks(5,5,5,5);
    test.GenBenchmarkTab(mark_test, 5);
    test.ShowTable();






}