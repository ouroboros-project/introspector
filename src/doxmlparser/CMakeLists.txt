

set (
  OP_DOXMLPARSER_CXX_FLAGS
  -pipe -fsigned-char -D_LARGEFILE_SOURCE
  ${OP_INTROSPECTOR_CXX_FLAGS}
)

set (
  OP_DOXMLPARSER_HEADERS
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
  OP_DOXMLPARSER_SOURCES
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

add_library (${OP_DOXMLPARSER_LIBRARY} ${OP_DOXMLPARSER_SOURCES} ${OP_DOXMLPARSER_HEADERS})

target_compile_options (
  ${OP_DOXMLPARSER_LIBRARY}
  PUBLIC  ${OP_DOXMLPARSER_CXX_FLAGS}
  PRIVATE ${OP_DOXMLPARSER_CXX_FLAGS}
)

target_include_directories (
  ${OP_DOXMLPARSER_LIBRARY}
  PUBLIC  ${OP_QTOOLS_DIR} ${OP_DOXMLPARSER_DIR}
  PRIVATE ${OP_QTOOLS_DIR} ${OP_DOXMLPARSER_DIR}
)

