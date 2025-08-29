cmake_minimum_required(VERSION 3.10)
make_directory(build/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)
set(CMAKE_CXX_STANDARD 23)

#-------------------------------------------
add_subdirectory(vendor/GLFW)
#-------------------------------------------
project(MyProject VERSION 1.0 LANGUAGES C CXX)
find_package(OpenGL REQUIRED)

add_library(StratEngine 
    STATIC
        StratEngine/StratEngine.h
        StratEngine/src/Core.cpp
        StratEngine/src/Core.h
        StratEngine/src/WinWindow/WinWindow.cpp
        StratEngine/src/WinWindow/WinWindow.h
        # GLAD files
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLAD/include/glad/glad.h
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLAD/src/glad.c
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLAD/include/KHR/khrplatform.h
        )

target_link_libraries(StratEngine 
    PUBLIC 
        glfw
        OpenGL::GL
        )

target_include_directories(StratEngine 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/StratEngine
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW/include/GLFW
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLAD/include/
        )

#-------------------------------------------

add_executable(MyApp UserApplication/Application.cpp)

target_link_libraries(MyApp PRIVATE StratEngine)

target_include_directories(MyApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/StratEngine)

