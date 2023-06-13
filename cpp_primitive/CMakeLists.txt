cmake_minimum_required(VERSION 3.25)
project(cpp_primitive)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_primitive main.cpp String.cpp String.h stadfx.h Shape.cpp Shape.h Singleton.cpp Singleton.h Observerable.cpp Observerable.cpp Observerable.h Observer.h)
