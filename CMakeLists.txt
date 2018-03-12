cmake_minimum_required(VERSION 3.9)
project(RandomnessProperties)

FIND_PACKAGE( Boost 1.58 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

set(CMAKE_CXX_STANDARD 11)

add_executable(RandomnessProperties main.cpp StatisticalTest.cpp StatisticalTest.h)

#TARGET_LINK_LIBRARIES(StatisticalTest.h LINK_PUBLIC ${Boost_LIBRARIES} )

