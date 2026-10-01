cmake_minimum_required(VERSION 3.20)
project(lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Debug | Release | RelWithDebInfo" FORCE)
endif()

option(ENABLE_SANITIZERS OFF)

function(oop_flags target)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4 /Zi)
        target_link_options(${target} PRIVATE /DEBUG)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic -g)
        if(ENABLE_SANITIZERS)
            target_compile_options(${target} PRIVATE -fsanitize=address,undefined)
            target_link_options(${target} PRIVATE -fsanitize=address,undefined)
        endif()
    endif()
endfunction()

include(FetchContent)
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.15.2)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

function(add_test name source_dir)
    add_executable(${name} ${source_dir}/tests.cpp ${ARGN})
    oop_flags(${name})
    target_include_directories(${name} PRIVATE ${source_dir})
    target_link_libraries(${name} PRIVATE GTest::gtest_main)
    gtest_discover_tests(${name})
endfunction()

add_executable(oop_lab1 main.cpp array_ops.cpp)
oop_flags(oop_lab1)
add_test(oop_lab1_tests ${CMAKE_CURRENT_SOURCE_DIR}/tests ${CMAKE_CURRENT_SOURCE_DIR}/array_ops.cpp)