project(MinipascalNodes)

cmake_minimum_required(VERSION 2.8)

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package( Boost 1.36.0 COMPONENTS system )

if(Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
        add_library(minipascalnodes 
                        minipascal_ndeclaration.cpp 
                        minipascal_nexpression.cpp 
                        minipascal_nstatement.cpp 
                        minipascal_nmethoddeclaration.cpp 
                        minipascal_nvariabledeclaration.cpp 
                        minipascal_nprogram.cpp 
                        minipascal_nstring.cpp 
                        minipascal_ndouble.cpp 
                        minipascal_nint.cpp 
                        minipascal_nboolean.cpp 
                        minipascal_nvalue.cpp 
                        minipascal_nmethodcall.cpp 
                        minipascal_nbinaryoperator.cpp 
                        minipascal_nvariable.cpp 
                        minipascal_nassignment.cpp 
                        minipascal_ncontrol.cpp 
                        minipascal_nloop.cpp 
                        minipascal_nstatementexpression.cpp 
                        minipascal_type.cpp 
                        minipascal_visitor.cpp 
                        minipascal_nblock.cpp 
                        minipascal_node.cpp)
        target_link_libraries(minipascalnodes ${Boost_LIBRARIES})
endif()
