# Logic static library
add_library(logic STATIC
    logic.cpp
    logic.h
    version_manager.cpp
    version_manager.h
)

target_include_directories(logic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(logic PUBLIC common)

add_subdirectory(common)
add_subdirectory(code)
target_link_libraries(logic PUBLIC pubsub_demo)
