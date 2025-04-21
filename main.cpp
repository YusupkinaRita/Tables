#include <iostream>
#include"ArrayTable.h"
#include "TableTestKit.h"
#include "Table.h"
#include "ScanTable.h"


int main(){
    ScanTable table=ScanTable(100);
    TableTestKit test=TableTestKit(table);
    test.GenBenchmarkTab(100);
    test.ShowTable();
    






}