project(AES_demo)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++0x -O2 -g3 -fPIC")
cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)

FIND_PACKAGE (PkgConfig REQUIRED)

FILE(GLOB SRC_LIST "src/*.cpp"
                   "src/*.h"
    )

ADD_EXECUTABLE(AES_demo  ${SRC_LIST} )
TARGET_LINK_LIBRARIES(AES_demo -lcrypto -fno-stack-protector)
