# logic/code CMake配置
add_library(pubsub_demo STATIC
    pubsub_demo.h
    pubsub_demo.cpp
)

target_link_libraries(pubsub_demo PUBLIC common)
target_include_directories(pubsub_demo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
