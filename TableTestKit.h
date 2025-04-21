#pragma once
#include "Table.h"


class TableTestKit{
private:
    Table& _table;


public:
    TableTestKit(Table& table):_table(table){
    };
    void FillTable();

    void GenBenchmarkTab(size_t size=100);//генерация таблицы какой-то(?)

    void ShowTable();

    void FindRecord();//запуск на 100 рандомно выбранных записях
    void DelRecord();//запуск на 100 рандомно выбранных записях

    void PrintMetricsFind();//распечатать количество итераций, время и ошибки на выполнение какой-то задачи

    void PrintMetricsDel();



};