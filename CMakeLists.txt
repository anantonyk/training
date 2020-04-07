cmake_minimum_required(VERSION 3.10.2)


project(env C)

add_executable(env main.c)

add_library(env_lib SHARED env_var.h env_var.c)
target_link_libraries(env env_lib)


INSTALL(TARGETS env DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)
