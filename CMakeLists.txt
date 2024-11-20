cmake_minimum_required(VERSION 3.29)
project(scope_bug)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
set(SIMPLE_SOCKET_BUILD_TESTS OFF)
FetchContent_Declare(
        SimpleSocket
        GIT_REPOSITORY https://github.com/markaren/SimpleSocket.git
        GIT_TAG e0e989bdd52137d743a4599e25167d5681a0de00
)
FetchContent_MakeAvailable(SimpleSocket)

add_executable(serverimpl1 serverimpl1.cpp)
target_link_libraries(serverimpl1 PRIVATE simple_socket)

add_executable(serverimpl2 serverimpl2.cpp)
target_link_libraries(serverimpl2 PRIVATE simple_socket)

add_executable(clientimpl client.cpp)
target_link_libraries(clientimpl PRIVATE simple_socket)
