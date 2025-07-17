cmake_minimum_required(VERSION 3.16)
project(QtWidgetExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(mylib src/math.cpp src/matrix.cpp)
add_executable(app main.cpp)
target_include_directories(mylib PUBLIC include)
target_link_libraries(app PRIVATE mylib Qt6::Widgets)

