# Main application
add_executable(app
    main.cpp
)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

target_link_libraries(app PRIVATE ui logic Qt6::Widgets)

target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
