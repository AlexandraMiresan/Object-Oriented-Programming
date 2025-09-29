cmake_minimum_required(VERSION 3.29)
project(e_915_AlexandraMiresan)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/mingw_64/lib/cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(e_915_AlexandraMiresan
    main.cpp
        Domain/Event.h
        Domain/Location.h
        Domain/Person.h
        Repository/EventsRepository.h
        Repository/EventsRepository.cpp
        Controller/PeopleController.h
        Repository/PeopleRepository.cpp
        Controller/PeopleController.cpp
        Controller/EventsController.h
        GUI/personwindow.cpp
        GUI/personwindow.h
        GUI/personwindow.ui
        TableModel/TableModel.h
        TableModel/TableModel.cpp
        Observer/Subject.h
        Observer/Observer.h
        Controller/EventsController.cpp
)

target_link_libraries(e_915_AlexandraMiresan PRIVATE Qt6::Widgets)