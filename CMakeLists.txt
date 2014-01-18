PROJECT(clab)
SET(CMAKE_VERBOSE_MAKEFILE ON)

ADD_SUBDIRECTORY(src/lib bin/lib)
ADD_SUBDIRECTORY(src/test bin/test)
ADD_SUBDIRECTORY(src/main bin/main)
ADD_SUBDIRECTORY(src/unito bin/unito)
