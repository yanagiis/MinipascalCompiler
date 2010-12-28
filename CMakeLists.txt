project(minipascalcompiler)

cmake_minimum_required(VERSION 2.8)

add_subdirectory(Nodes)

find_package(FLEX)
find_package(BISON)

BISON_TARGET(MinipascalParser minipascal_parser.yy minipascal_parser.cpp)
FLEX_TARGET(MinipascalScanner minipascal_scanner.lex minipascal_scanner.cpp)
ADD_FLEX_BISON_DEPENDENCY(MinipascalScanner MinipascalParser)

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package( Boost 1.36.0 COMPONENTS system)
if(Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
        include_directories(${minipascalcompiler_SOURCE_DIR}/Nodes)
        add_executable(minipascalcompiler main.cpp ../${BISON_MinipascalParser_OUTPUTS} ../${FLEX_MinipascalScanner_OUTPUTS} minipascal_driver.cpp ) 
        target_link_libraries(minipascalcompiler ${Boost_LIBRARIES} ${minipascalnodes})
endif()