
set (OP_QTOOLS_DIR "${CMAKE_CURRENT_LIST_DIR}/qtools")
set (OP_QTOOLS_LIBRARY qtools)

add_subdirectory (qtools)

set (OP_DOXMLPARSER_DIR "${CMAKE_CURRENT_LIST_DIR}/doxmlparser")
set (OP_DOXMLPARSER_LIBRARY doxmlparser)

add_subdirectory (doxmlparser)

set (OP_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/op")

add_subdirectory (op)

