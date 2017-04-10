cmake_minimum_required(VERSION 3.6)
project(Arvorebinaria)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp node.cpp node.h Arvore.cpp Arvore.h Buscabinaria.cpp Buscabinaria.h)
add_executable(Arvorebinaria ${SOURCE_FILES})