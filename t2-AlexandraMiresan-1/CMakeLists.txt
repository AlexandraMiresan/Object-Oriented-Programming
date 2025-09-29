cmake_minimum_required(VERSION 3.29)
project(t2_AlexandraMiresan_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t2_AlexandraMiresan_1
    Controller.cpp
    Controller.h
    HospitalDepartment.cpp
    HospitalDepartment.h
    NeonatalUnit.cpp
    NeonatalUnit.h
    Surgery.cpp
    Surgery.h
        UI.h
        UI.cpp
        main.cpp)
