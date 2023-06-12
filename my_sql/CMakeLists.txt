cmake_minimum_required(VERSION 3.25)
project(my_sql)

set(CMAKE_CXX_STANDARD 17)

include_directories(D:/LenovoSoftstore/mysql/include) ##本机MySQL下的include路径
link_directories(D:/LenovoSoftstore/mysql/lib) ##本机MySQL下的lib路径
link_libraries(libmysql) ##这个这样填就行

add_executable(my_sql main.cpp)

target_link_libraries(my_sql libmysql) ##Clion改为自己的工程文件
