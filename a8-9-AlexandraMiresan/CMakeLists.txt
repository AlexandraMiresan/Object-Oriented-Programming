cmake_minimum_required(VERSION 3.14)  # 3.14+ is fine unless you need 3.29 features
project(a8_9_AlexandraMiresan)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set Qt6 path (adjust as needed)
set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/mingw_64/lib/cmake")


# Enable Qt MOC, UIC, RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find required Qt components
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Add source files
add_executable(a8_9_AlexandraMiresan
        main.cpp
        Domain/Event.cpp
        Domain/IdGenerator.cpp
        Repository/CSVEventList.cpp
        Repository/EventList.cpp
        Repository/HTMLEventList.cpp
        Repository/Repository.cpp
        Service/Administrator.cpp
        Service/User.cpp
        Tests/Tests.cpp
        UI/UI.cpp
        UI/GUI.cpp
        guidesigner.h
        guidesigner.cpp
)

# Link Qt6 libraries
target_link_libraries(a8_9_AlexandraMiresan PRIVATE Qt6::Widgets)
