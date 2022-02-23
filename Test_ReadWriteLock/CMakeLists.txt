cmake_minimum_required(VERSION 3.17)

project(Test_ReadWriteLock)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test_ReadWriteLock main.cpp ReadWriteLock.h)