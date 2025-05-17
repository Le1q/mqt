cmake_minimum_required(VERSION 3.16)
project(QtSplitLibsDemo LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "C:/Qt/6.5.3/mingw_64")

# UI static library
add_subdirectory(ui)
# Logic static library
add_subdirectory(logic)
# Main application
add_subdirectory(app)
