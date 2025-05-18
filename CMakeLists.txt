cmake_minimum_required(VERSION 3.16)
project(QtSplitLibsDemo LANGUAGES CXX)

# 设置 C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# MSVC 特定选项
if(MSVC)
    add_compile_options(/utf-8 /Zc:__cplusplus)
endif()

set(CMAKE_PREFIX_PATH "C:/Qt/6.5.3/mingw_64")

# 配置 OpenCV
set(OpenCV_DIR "C:/opencv-mingw/x64/mingw/lib")
set(OpenCV_STATIC OFF)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# UI static library
add_subdirectory(ui)
# Logic static library
add_subdirectory(logic)
# Main application
add_subdirectory(app)
