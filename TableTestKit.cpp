#include "TableTestKit.h"
#include "ArrayTable.h"
#include <chrono>
#include <fstream>
#include <filesystem>
#include <random>

static Key GenRandKey(std::mt19937& rng, size_t size=8){
    std::string letters= "abcdefghijklmnopqrstuvwxyz";

    std::uniform_int_distribution<> dist(0, letters.size() - 1);

    std::string res_key="";

    for(size_t i=0; i<size; i++){
        if(i==0)
            res_key+=std::toupper(letters[dist(rng)]);
        res_key+=letters[dist(rng)];
   }
   return res_key;
}


void TableTestKit::GenBenchmarkTab(PDatValue tmp, std::string filename, size_t size){
    _size=size;
    if (std::filesystem::exists(filename)) {
        std::ifstream file_s(filename);

        std::string line;
        while (std::getline(file_s, line)) {
            std::istringstream iss(line);

            std::string name, surname;
            iss >> surname>> name;
            name.erase(name.size()-1);
            std::string key=surname+" "+ name;
            //_table.Reset();
            // if(key==_table.GetKey()){
            //     return ;
            // }
            std::string val_str;
            std::getline(iss, val_str);
            val_str.erase(0, 1);
            PDatValue val=tmp->GetCopy();
            val->Deserialise(val_str);
            _table.InsRecord(key, val);
            _keys.push_back(key);
        }
    }
    else{
        std::mt19937 rng(std::random_device{}());
        std::ofstream out(filename);
        if (!out.is_open()) {
            std::cerr << "Error opening file for writing\n";
            return;
        }
        for(size_t i=0;i<size;i++){
            std::string key=GenRandKey(rng,9)+" "+ GenRandKey(rng,5);
            PDatValue val=tmp->GetRand();
            _table.InsRecord(key, val);
            _keys.push_back(key);

            out<<key<<": "<<val->ToStr()<<"\n";
    
        }


    }
    std::cout<<"benchmark done"<<std::endl;
    
}

void TableTestKit::ShowTable(){
    if(_table.IsEmpty())
        throw "table is empty";
    _table.Reset();
    
    bool x=0;
    while(x!=1){
        std::cout << "Key: " << _table.GetKey()<< ", Value: "<<*(_table.GetValuePtr())<<std::endl;
        x=_table.GoNext();
        
    }

}

void TableTestKit::FindRecord(size_t size){
    _find_efficiency=0;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, _table.GetDataCount()-1);


    for(size_t i=0;i<size;i++){
        size_t x=dist(rng);
        if(_table.FindRecord(_keys[x])==nullptr)
            _find_errors++;

        
        size_t cur_find_eff=_table.GetEfficiency();
        if(cur_find_eff>_max_find_eff){
            _max_find_eff=cur_find_eff;
        }
        if(cur_find_eff<_min_find_eff)
            _min_find_eff=cur_find_eff;
        
        _find_efficiency+=cur_find_eff;

    }
    _overall_efficiency+=_find_efficiency;

}
void TableTestKit::DelRecord(size_t size){
    _del_efficiency=0;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, _table.GetDataCount()-1);
    for(size_t i=0;i<size;i++){
        size_t x=dist(rng);
        try{_table.DelRecord(_keys[x]);}
        catch(const char*){
            _del_errors++;

        }
        size_t cur_del_eff=_table.GetEfficiency();
        if(cur_del_eff>_max_del_eff){
            _max_del_eff=cur_del_eff;
        }
        if(cur_del_eff<_min_del_eff)
            _min_del_eff=cur_del_eff;
        
        _del_efficiency+=cur_del_eff;

    }
    _overall_efficiency+=_del_efficiency;

}

void TableTestKit::PrintMetrics(size_t count){
    auto start1 = std::chrono::high_resolution_clock::now();
    FindRecord(count);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    std::cout << "Time for find: " << duration1.count() << std::endl;
    std::cout << "Errors for find: " << _find_errors<< std::endl;
    std::cout << "Average efficiency for find: " << _find_efficiency/count<< std::endl;
    std::cout << "Max efficiency for find: " << _max_find_eff<< std::endl;
    std::cout << "Min efficiency for find: " << _min_find_eff<< std::endl;

    
    std::cout<<std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    DelRecord(count);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
    std::cout << "Time for delete: " << duration2.count() << std::endl;
    std::cout << "Errors for delete: " << _del_errors<< std::endl;
    std::cout << "Average efficiency for delete: " << _del_efficiency/count<< std::endl;
    std::cout << "Max efficiency for delete: " << _max_del_eff<< std::endl;
    std::cout << "Min efficiency for delete: " << _min_del_eff<< std::endl;

    //std::cout<<"overall effiviency:"<<_overall_efficiency<<std::endl;

    

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