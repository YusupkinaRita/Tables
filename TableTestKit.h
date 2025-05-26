#pragma once
#include "Table.h"
#include <vector>


class TableTestKit{
private:
    Table& _table;
    std::vector<std::string> _keys;
    size_t _overall_efficiency=0;
    size_t _find_errors=0;
    size_t _del_errors=0;
    


public:
    TableTestKit(Table& table):_table(table){
    };
    void FillTable();//не хочу

    void GenBenchmarkTab(PDatValue tmp, size_t size=100);//генерация таблицы какой-то(?)в файл и из файла считать в _table

    void ShowTable();

    void FindRecord();//запуск на 100 рандомно выбранных записях
    void DelRecord();//запуск на 100 рандомно выбранных записях

    void PrintMetrics();//распечатать количество итераций, время и ошибки на выполнение какой-то задачи

    //void PrintMetricsDel();



};