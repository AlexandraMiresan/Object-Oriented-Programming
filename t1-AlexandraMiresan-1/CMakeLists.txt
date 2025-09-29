cmake_minimum_required(VERSION 3.29)
project(t1_AlexandraMiresan_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t1_AlexandraMiresan_1
    .gitignore
    DynamicVector.h
    README.md
        main.cpp
        UI.h
        UI.cpp
        Service.h
        WeatherStation.h
        WeatherStation.cpp
        Repository.h
        Repository.cpp
        Service.cpp
        Tests.h
        Tests.cpp)
