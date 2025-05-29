#pragma once
#include "Table.h"
#include <vector>


class TableTestKit{
private:
    Table& _table;
    size_t _size=0;
    std::vector<std::string> _keys;
    size_t _overall_efficiency=0;
    size_t _find_errors=0;
    size_t _del_errors=0;
    size_t _max_find_eff=0;
    size_t _max_del_eff=0;
    size_t _min_find_eff=100000000000;
    size_t _min_del_eff=10000000000000;

    size_t _find_efficiency=0;
    size_t _del_efficiency=0;
    


public:
    TableTestKit(Table& table):_table(table){
    };
    void FillTable();//не хочу

    void GenBenchmarkTab(PDatValue tmp,std::string filename, size_t size=100);//генерация таблицы какой-то(?)в файл и из файла считать в _table

    void ShowTable();

    void FindRecord(size_t size);//запуск на 100 рандомно выбранных записях
    void DelRecord(size_t size);//запуск на 100 рандомно выбранных записях

    void PrintMetrics(size_t size);//распечатать количество итераций, время и ошибки на выполнение какой-то задачи

    //void PrintMetricsDel();



};