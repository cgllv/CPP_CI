cmake_minimum_required(VERSION 2.8.0)
project(ModernCppCI)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG on)
find_package(Threads REQUIRED)

add_subdirectory(third_party EXCLUDE_FROM_ALL)
add_subdirectory(lib)

enable_testing()