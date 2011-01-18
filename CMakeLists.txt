project(minipascalcompiler)

cmake_minimum_required(VERSION 2.8)

find_package(FLEX)
find_package(BISON)

# BISON_TARGET(MinipascalParser minipascal_parser.yy minipascal_parser.cpp)
# FLEX_TARGET(MinipascalScanner minipascal_scanner.lex minipascal_scanner.cpp)
# ADD_FLEX_BISON_DEPENDENCY(MinipascalScanner MinipascalParser)

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package( Boost 1.36.0 COMPONENTS system)
if(Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
        include_directories(${minipascalcompiler_SOURCE_DIR}/Nodes)
        link_directories(${minipascalcompiler_BINARY_DIR}/Nodes)
        add_subdirectory(Nodes)
        add_subdirectory(Checkers)
        add_definitions(-I/usr/include  -DNDEBUG -D_GNU_SOURCE -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS )
        add_definitions(-L/usr/lib/llvm  -lpthread -lffi -ldl -lm)
        add_executable(minipascalcompiler main.cpp minipascal_parser.cpp minipascal_scanner.cpp minipascal_driver.cpp) 
        target_link_libraries(minipascalcompiler ${Boost_LIBRARIES} minipascalnodes minipascalcheckers)
#         add_executable(minipascalcompiler main.cpp ../${BISON_MinipascalParser_OUTPUTS} ../${FLEX_MinipascalScanner_OUTPUTS} minipascal_driver.cpp) 
#         target_link_libraries(minipascalcompiler ${Boost_LIBRARIES} minipascalnodes minipascalcheckers)
endif()