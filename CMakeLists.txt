# Set up cmake
cmake_minimum_required (VERSION 3.0)
project (test_elipse CXX C)
if (WIN32)
  add_compile_options(-std:c++17)
else ()
  add_compile_options(-std=c++17 -Wall -Wextra)
endif()

# Find LIbrary
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

add_library(ellipse_test SHARED src/customwidget.cpp src/customwidget.h src/ellipseitem.cpp src/ellipseitem.h src/ellipsetest.cpp src/ellipsetest.h src/ellipsetest.ui src/ellipse_test_exports.h)
target_link_libraries(ellipse_test Qt5::Core Qt5::Widgets)

add_executable(ellipse_test_main src/ellipse_test_main.cpp)
target_link_libraries(ellipse_test_main Qt5::Core ellipse_test)
