
set (OP_QTOOLS_DIR "${CMAKE_CURRENT_LIST_DIR}/qtools")
set (OP_QTOOLS_LIBRARY qtools)

set (OP_INTROSPECTOR_CXX_FLAGS -Wall -W -std=c++11 -O0 -g)

add_subdirectory (qtools)

set (OP_DOXMLPARSER_DIR "${CMAKE_CURRENT_LIST_DIR}/doxmlparser")
set (OP_DOXMLPARSER_LIBRARY doxmlparser)

add_subdirectory (doxmlparser)

set (OP_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}")

add_subdirectory (op)

