cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_PREFIX_PATH /usr/bin/g++)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_VERBOSE_MAKEFILE ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)



#include_directories(${/Desktop/cviceni/cviceniPPC/cviceni9QT/groupbox})
#set(SOURCES main.cpp main.cpp ${/Desktop/cviceni/cviceniPPC/cviceni9QT/groupbox})

add_definitions("-std=c++17")

set(Qt5Widgets_DIR /usr/bin/g++)

project(Space_Explorer)

find_package(Qt5Widgets)

set(PUBLIC_HEADER player.h)

add_executable(Space_Explorer main.cpp player.cpp)
#add_executable(project main.cpp player.h)




#add_executable(project main.cpp style.qrc) pridavani vice zdroju se kterymi cmake pracuje
#i header soubory se daji pridat do tohoto prikazu a nekdy to muze resit problem s kompilaci

#qt5_use_modules(contact widgets)

target_link_libraries(Space_Explorer Qt5::Widgets)
