#include "TableTestKit.h"
#include "ArrayTable.h"
#include <chrono>
#include <fstream>
#include <filesystem>
#include <random>

static Key GenRandKey(size_t size=8){
    std::string letters= "abcdefghijklmnopqrstuvwxyz";

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, letters.size() - 1);

    std::string res_key="";

    for(size_t i=0; i<size; i++){
        if(i==0)
            res_key+=std::toupper(letters[dist(rng)]);
        res_key+=letters[dist(rng)];
   }
   return res_key;
}





void TableTestKit::GenBenchmarkTab(size_t size){
    std::string filename="benchmark.txt";
    




}

void TableTestKit::ShowTable(){
    if(_table.IsEmpty())
        throw "table is empty";
    _table.Reset();
    bool x=0;
    while(x!=1){
        std::cout << "Key: " << _table.GetKey()<< ", Value: " << *(_table.GetValuePtr()) << std::endl;
        x=_table.GoNext();
        
    }

}

void TableTestKit::FindRecord(){
    for(size_t i=0;i<100;i++){
        int x=rand()%100;
        _table.FindRecord("Key"+std::to_string(x));
    }

}
void TableTestKit::DelRecord(){
    for(size_t i=0;i<100;i++){
        int x=rand()%100;
        _table.DelRecord("Key"+std::to_string(x));
    }

}

// void TableTestKit::PrintMetricsFind(){
//     GenBenchmarkTab();
//     int exception_count=0;
//     auto start = std::chrono::high_resolution_clock::now();
//     try{FindRecord();}
//     catch(const char* error_message){
//         exception_count++;
//     }
//     auto end = std::chrono::high_resolution_clock::now();
//     auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//     std::cout << "Time for find: " << duration.count() << std::endl;
//     std::cout<<"exceptions in find: "<<exception_count<<std::endl;
//     std::cout<<"efficiensy for find is"<<_table.GetEfficiency()<<std::endl;
    
// }

// void TableTestKit::PrintMetricsDel(){
//     GenBenchmarkTab();
//     int exception_count=0;
//     auto start = std::chrono::high_resolution_clock::now();
//     try{DelRecord();}
//     catch(const char* error_message){
//         exception_count++;
//     }
//     auto end = std::chrono::high_resolution_clock::now();
//     auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//     std::cout << "Time for delete: " << duration.count() << std::endl;
//     std::cout<<"exceptions in delete: "<<exception_count<<std::endl;
//     std::cout<<"efficiensy for delete is"<<_table.GetEfficiency()<<std::endl;
    
// }