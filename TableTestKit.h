#pragma once
#include "Table.h"
#include <vector>


class TableTestKit{
private:
    Table& _table;
    std::vector<std::string> _keys;
    size_t _find_errors;
    size_t _del_errors;
    


public:
    TableTestKit(Table& table):_table(table){
    };
    void FillTable();

    void GenBenchmarkTab(size_t size=100);//генерация таблицы какой-то(?)в файл и из файла считать в _table

    void ShowTable();

    void FindRecord();//запуск на 100 рандомно выбранных записях
    void DelRecord();//запуск на 100 рандомно выбранных записях

    void PrintMetrics();//распечатать количество итераций, время и ошибки на выполнение какой-то задачи

    //void PrintMetricsDel();



};