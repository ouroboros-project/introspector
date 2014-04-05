
cmake_minimum_required (VERSION 2.8.12)

project (ouroboros-introspector CXX C)

find_package (Doxygen REQUIRED)

set (OP_BINDIR ${CMAKE_CURRENT_BINARY_DIR}/bin)
set (OP_LIBDIR ${CMAKE_CURRENT_BINARY_DIR}/lib)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OP_BINDIR})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OP_LIBDIR})
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OP_LIBDIR})

add_subdirectory (src)

