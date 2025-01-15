cmake_minimum_required(VERSION 3.29)
project(Project)

set(CMAKE_CXX_STANDARD 20)

# Set the path to the Qt installation
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.1/mingw_64/bin")

# Find the required Qt components
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Enable automatic Qt processing
set(CMAKE_AUTOMOC ON)  # Automatically generate MOC files
set(CMAKE_AUTOUIC ON)  # Automatically process .ui files
set(CMAKE_AUTORCC ON)  # Automatically process .qrc files

# Add your executable and include .ui files explicitly
add_executable(Project
        main.cpp
        admin.cpp
        admin.h
        admin.ui
        student.cpp
        student.h
        student.ui
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Hash.cpp
        Hash.h
        display.cpp
        display.h
        display.ui
)

# Link the Qt libraries to your project
target_link_libraries(Project Qt6::Widgets)

# Include directories for Qt (optional)
include_directories(${Qt6Widgets_INCLUDE_DIRS})
