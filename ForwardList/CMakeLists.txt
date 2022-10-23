cmake_minimum_required(VERSION 3.22)

project(forward_list)

set(SOURCE
    main.cpp
)

set(HEADER 
    forward_list.h
)

add_executable(forward_list ${SOURCE})