cmake_minimum_required(VERSION 3.1)
project(game)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_INSTALL_RPATH "${PROJECT_SOURCE_DIR}/bin")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(game main.cpp game.cpp army.cpp artillery.cpp infantry.cpp tank.cpp visitor.cpp rocket.cpp observer.cpp army_factory.h soviet_army_factory.cpp german_army_factory.cpp artillery_adapter.cpp subdivision.cpp)

enable_testing()
add_executable(Test tests.cpp army.cpp artillery.cpp infantry.cpp tank.cpp visitor.cpp rocket.cpp observer.cpp army_factory.h soviet_army_factory.cpp german_army_factory.cpp artillery_adapter.cpp subdivision.cpp)

add_test(Test ${Testing_SOURCE_DIR}/bin/testing_game)

target_link_libraries(Test Threads::Threads ${GTEST_LIBRARIES} ${GMOCK_BOTH_LIBRARIES})

install (
        TARGETS Test
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
)

install (
        TARGETS game
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
)
