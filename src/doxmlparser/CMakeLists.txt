
set (DOXMLPARSER_LIBRARY doxmlparser)

#set (DOXMLPARSER_CXX_FLAGS "-pipe -fsigned-char -D_LARGEFILE_SOURCE -Wall -W -O2")
set (DOXMLPARSER_CXX_FLAGS -pipe -fsigned-char -Wall -W -O2)

set (
  DOXMLPARSER_HEADERS
  basehandler.h
  mainhandler.h
  compoundhandler.h
  sectionhandler.h
  memberhandler.h
  paramhandler.h
  dochandler.h
  linkedtexthandler.h
  debug.h
  graphhandler.h
  stringimpl.h
  loamhandler.h
)

set (
  DOXMLPARSER_SOURCES
  mainhandler.cpp
  compoundhandler.cpp
  sectionhandler.cpp
  memberhandler.cpp
  paramhandler.cpp
  dochandler.cpp
  linkedtexthandler.cpp
  basehandler.cpp
  debug.cpp
  graphhandler.cpp
  loamhandler.cpp
)

add_library (${DOXMLPARSER_LIBRARY} ${DOXMLPARSER_SOURCES} ${DOXMLPARSER_HEADERS})

target_compile_options (
  ${DOXMLPARSER_LIBRARY}
  PUBLIC ${DOXMLPARSER_CXX_FLAGS}
)

target_include_directories (
  ${DOXMLPARSER_LIBRARY}
  PUBLIC  ${OP_QTOOLS_DIR} ${CMAKE_CURRENT_LIST_DIR}
  PRIVATE ${OP_QTOOLS_DIR} ${CMAKE_CURRENT_LIST_DIR}
)

