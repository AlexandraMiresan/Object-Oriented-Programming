cmake_minimum_required(VERSION 3.29)
project(a10_AlexandraMiresan_1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/mingw_64/lib/cmake")

# Enable Qt MOC, UIC, RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find required Qt components
find_package(Qt6 REQUIRED COMPONENTS Widgets)



include_directories(Domain)
include_directories(Repository)
include_directories(Service)

add_executable(a10_AlexandraMiresan_1
    Domain/Event.cpp
    Domain/Event.h
    Domain/IdGenerator.cpp
    Domain/IdGenerator.h
    Repository/CSVEventList.cpp
    Repository/CSVEventList.h
    Repository/EventList.cpp
    Repository/EventList.h
    Repository/HTMLEventList.cpp
    Repository/HTMLEventList.h
    Repository/Repository.cpp
    Repository/Repository.h
    Service/Administrator.cpp
    Service/Administrator.h
    Service/User.cpp
    Service/User.h
    main.cpp
        UndoRedo/UndoRedoAdd.h
        UndoRedo/UndoRedoRemove.h
        UndoRedo/UndoRedoUpdate.h
        guidesigner.cpp
        UserModel.h
        UserModel.cpp)


target_link_libraries(a10_AlexandraMiresan_1 PRIVATE Qt6::Widgets)