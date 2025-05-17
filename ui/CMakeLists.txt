set(CMAKE_AUTOMOC ON)

# UI static library
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt6_wrap_ui(UISrcs mainwindow.ui)
add_library(ui STATIC
    mainwindow.cpp
    mainwindow.h
    ${UISrcs}
)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

target_link_libraries(ui PUBLIC Qt6::Widgets logic)

target_include_directories(ui PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_BINARY_DIR}/ui 
    ${CMAKE_SOURCE_DIR}
)
