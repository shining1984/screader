CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(scread)

ADD_EXECUTABLE(scread scread.c)
INCLUDE_DIRECTORIES(./include/)

#Need to do more about find library#
FIND_LIBRARY(LIBCLANG_PATH clang HINTS /usr/local/lib/)

TARGET_LINK_LIBRARIES(scread ${LIBCLANG_PATH})
