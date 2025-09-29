cmake_minimum_required(VERSION 3.29)
project(a6_7_AlexandraMiresan)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(Domain)
include_directories(Repository)
include_directories(Service)
include_directories(Tests)
include_directories(UI)

add_executable(a6_7_AlexandraMiresan
    .idea/inspectionProfiles/Project_Default.xml
    .idea/.gitignore
    .idea/a6-7-AlexandraMiresan.iml
    .idea/editor.xml
    .idea/modules.xml
    .idea/vcs.xml
    Domain/Event.cpp
    Domain/Event.h
    Domain/IdGenerator.cpp
    Domain/IdGenerator.h
    .gitignore
    example.csv
    example.html
    README.md
        Repository/Repository.h
        Repository/Repository.cpp
        Service/Administrator.h
        Service/Administrator.cpp
        Service/User.h
        Service/User.cpp
        UI/UI.h
        UI/UI.cpp
        main.cpp
        Tests/Tests.h
        Tests/Tests.cpp
        Validators/RepositoryValidator.h
        Repository/EventList.h
        Repository/EventList.cpp
        Repository/CSVEventList.h
        Repository/CSVEventList.cpp
        Repository/HTMLEventList.h
        Repository/HTMLEventList.cpp
)
