cmake_minimum_required(VERSION 3.28.3)
project(a4_5_AlexandraMiresan)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(a4_5_AlexandraMiresan
    .idea/inspectionProfiles/Project_Default.xml
    .idea/.gitignore
    .idea/a4-5-AlexandraMiresan.iml
    .idea/editor.xml
    .idea/modules.xml
    .idea/vcs.xml
    main.cpp
        Domain/Event.h
        Domain/IdGenerator.h
        Domain/IdGenerator.cpp
        Domain/Event.cpp
        DynamicVector/DynamicVector.h
        Domain/Event.cpp
        Domain/Event.cpp
        Service/Administrator.h
        Service/Administrator.cpp
        Service/User.h
        Service/User.cpp
        Repository/Repository.h
        Repository/Repository.cpp
        UI/UI.h
        UI/UI.cpp
        Tests/Tests.cpp
)
