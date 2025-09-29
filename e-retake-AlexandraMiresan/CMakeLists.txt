cmake_minimum_required(VERSION 3.29)
project(e_retake_AlexandraMiresan)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/mingw_64/lib/cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)


add_executable(e_retake_AlexandraMiresan
    main.cpp
        Domain/Chef.h
        Domain/Recipe.h
        Repository/ChefsRepo.h
        Repository/ChefsRepo.cpp
        Repository/RecipesRepo.h
        Repository/RecipesRepo.cpp
        Service/Chefs.h
        Service/Recipes.h
        Observer/Observer.h
        Observer/Subject.h
        GUI/chefwindow.h
        GUI/chefwindow.cpp
        TableModel/TableModel.h
        TableModel/TableModel.cpp
        GUI/viewwindow.h
        GUI/viewwindow.cpp)
target_link_libraries(e_retake_AlexandraMiresan PRIVATE Qt6::Widgets)