# common层CMake配置
add_library(common STATIC
    pubsub_base.h
    pubsub_base.cpp
)

target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
