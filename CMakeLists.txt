cmake_minimum_required(VERSION 3.8)


project(CPlusPlusBestC
	LANGUAGES CXX)
	
	
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(main main.cpp TabRecord.cpp ArrayTable.cpp ScanTable.cpp SortTable.cpp HashTable.cpp TableTestKit.cpp ListHashTable.cpp ArrayHash.cpp TreeTable.cpp)
