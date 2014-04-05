
cmake_minimum_required (VERSION 2.8.11)

project (ouroboros-introspector CXX C)

find_package (Doxygen REQUIRED)

set (OP_LIBDIR ${CMAKE_CURRENT_LIST_DIR}/lib)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OP_LIBDIR})
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OP_LIBDIR})

add_subdirectory (src)

