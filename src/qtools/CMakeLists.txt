
set (
  OP_QTOOLS_CXX_FLAGS
  -pipe -fsigned-char -DQT_LITE_UNICODE -D_LARGEFILE_SOURCE
  -Wall -W -O2
)

set (
  OP_QTOOLS_HEADERS
  qarray.h qbuffer.h qcache.h qgcache.h qcollection.h qconfig.h
  qcstring.h scstring.h qdatastream.h qdatetime.h qdict.h qdir.h
  qfeatures.h qfile.h qfiledefs_p.h qfileinfo.h qgarray.h qfeatures.h
  qgdict.h qgeneric.h qglist.h qglobal.h qgstring.h qgvector.h
  qintdict.h qiodevice.h qlist.h qptrdict.h qqueue.h qregexp.h
  qshared.h qsortedlist.h qstack.h qstring.h qstringlist.h qstrlist.h
  qstrvec.h qtextstream.h qtl.h qvaluelist.h qvector.h qxml.h
  qvaluestack.h qmap.h qmodules.h qthread.h qthread_p.h qmutex.h
  qmutex_p.h qutfcodec.h qwaitcondition.h
)

set (
  OP_QTOOLS_SOURCES
  qbuffer.cpp qcollection.cpp scstring.cpp qdatastream.cpp qdatetime.cpp
  qdir.cpp qfile.cpp qfileinfo.cpp qgarray.cpp qgcache.cpp qgdict.cpp
  qglist.cpp qglobal.cpp qgstring.cpp qgvector.cpp qiodevice.cpp
  qregexp.cpp qstring.cpp qtextstream.cpp qtextcodec.cpp qstringlist.cpp
  qxml.cpp qmap.cpp qthread.cpp qmutex.cpp qutfcodec.cpp qfile_unix.cpp
  qdir_unix.cpp qfileinfo_unix.cpp qthread_unix.cpp qmutex_unix.cpp
  qwaitcondition_unix.cpp
)

add_library (${OP_QTOOLS_LIBRARY} ${OP_QTOOLS_SOURCES} ${OP_QTOOLS_HEADERS})

target_compile_options (
  ${OP_QTOOLS_LIBRARY}
  PUBLIC  ${OP_QTOOLS_CXX_FLAGS}
  PRIVATE ${OP_QTOOLS_CXX_FLAGS}
)

target_include_directories (
  ${OP_QTOOLS_LIBRARY}
  PUBLIC  ${OP_QTOOLS_DIR}
  PRIVATE ${OP_QTOOLS_DIR}
)

