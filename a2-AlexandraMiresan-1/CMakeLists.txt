cmake_minimum_required(VERSION 3.28.3)
project(a2_AlexandraMiresan_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a2_AlexandraMiresan_1
        main.c
        Repository/estates_repository.h
        UI/UI.h
        UI/UI.c
        Repository/estates_repository.c
        Domain/estate.h
        Controller/estateController.h
        Repository/estates_repository.c
        Controller/estateController.c
        DynnamicArray/dynnamicArray.h
        DynnamicArray/dynnamicArray.c
        Domain/estate.c
        UI/UI.c
        Repository/estates_repository.c
        Repository/estates_repository.c
        Domain/estateVector.h
)
