cmake_minimum_required(VERSION 3.1)
project(new_vector)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_INSTALL_RPATH "${PROJECT_SOURCE_DIR}/bin")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(new_vector main.cpp)

enable_testing()
add_executable(Test vector.h vector_tests.cpp)

add_test(Test ${Testing_SOURCE_DIR}/bin/testing_vector)

target_link_libraries(Test Threads::Threads ${GTEST_LIBRARIES} ${GMOCK_BOTH_LIBRARIES})

install(
    TARGETS Test
    RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
)

install(
    TARGETS new_vector
    RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
)
