cmake_minimum_required(VERSION 3.20)
project(gbemu VERSION 1.0 LANGUAGES CXX)

if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

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
    src/Opcodes.cpp
    src/Cartridge.cpp
    src/Processor.cpp
)
# our main application executable 
target_include_directories(gbemu PRIVATE include/)



add_executable(
    gbemu_tests
    src/tests/smoke_test.cpp
)
target_link_libraries(
    gbemu_tests
    GTest::gtest_main
)
if(WIN32)
    add_compile_definitions(OS_WINDOWS)
    target_link_libraries(gbemu PRIVATE wsock32 ws2_32)
elseif(APPLE)
    add_compile_definitions(OS_MAC)
    find_library(COCOA_LIBRARY Cocoa)
    target_link_libraries(gbemu PRIVATE ${COCOA_LIBRARY})

    if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
        set(LLVM_LIB_PATH "/opt/homebrew/opt/llvm/lib/c++")
    else()
        set(LLVM_LIB_PATH "/usr/local/opt/llvm/lib/c++")
    endif()

    target_compile_options(gbemu PRIVATE -stdlib=libc++)
    target_link_options(gbemu PRIVATE 
        -stdlib=libc++ 
        -L${LLVM_LIB_PATH}
        # Tell dyld at runtime: look HERE for libc++, not the system one
        -Wl,-rpath,${LLVM_LIB_PATH}
    )

    target_compile_options(gbemu_tests PRIVATE -stdlib=libc++)
    target_link_options(gbemu_tests PRIVATE 
        -stdlib=libc++ 
        -L${LLVM_LIB_PATH}
        # Same for the test binary
        -Wl,-rpath,${LLVM_LIB_PATH}
    )
endif()

target_include_directories(gbemu_tests PRIVATE include/)

include(GoogleTest)
gtest_discover_tests(gbemu_tests)