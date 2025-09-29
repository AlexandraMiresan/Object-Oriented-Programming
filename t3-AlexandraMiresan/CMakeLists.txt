cmake_minimum_required(VERSION 3.29)
project(t3_AlexandraMiresan)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/mingw_64/lib/cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(t3_AlexandraMiresan
    main.cpp
        TimeInterval.h
        TimeInterval.cpp
        Controller.h
        Controller.cpp
        gui.h
        gui.cpp)


find_package(Qt6 REQUIRED COMPONENTS Widgets)
target_link_libraries(t3_AlexandraMiresan PRIVATE Qt6::Widgets)