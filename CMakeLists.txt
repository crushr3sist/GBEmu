cmake_minimum_required(VERSION 3.20)
project(gbemu VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



# add google test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# for windows we need to prevent overriding the parent projects comp/link settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# our main application executable
add_executable(
    gbemu
    src/main.cpp
    src/test.cpp
)
# our main application executable 
target_include_directories(gbemu PRIVATE include/)

if(WIN32)
    add_compile_definitions(OS_WINDOWS)
    target_link_libraries(gbemu PRIVATE wsock32 ws2_32)
elseif(APPLE)
    add_compile_definitions(OS_MAC)
    find_library(COCOA_LIBRARY Cocoa)
    target_link_libraries(gbemu PRIVATE ${COCOA_LIBRARY})
endif()

add_executable(
    gbemu_tests
    src/test.cpp
    src/tests/smoke_test.cpp
)
target_link_libraries(
    gbemu_tests
    GTest::gtest_main
)

target_include_directories(gbemu_tests PRIVATE include/)

include(GoogleTest)
gtest_discover_tests(gbemu_tests)