cmake_minimum_required(VERSION 3.17)
project(Compiler)

set(CMAKE_CXX_STANDARD 20)

add_executable(Compiler SymbolTable.cpp SymbolInfo.h ScopeTable.h SymbolTable.h)