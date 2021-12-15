cmake_minimum_required(VERSION 3.13)
project(DangerousObjectSearcher)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} -mmacosx-version-min=12.0")
find_package(OpenCV REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(DangerousObjectSearcher main.cpp Views/GUI/GUI.cpp Views/GUI/GUI.h Views/ClickableLabel/ClickableLabel.cpp Views/ClickableLabel/ClickableLabel.h Views/TableWidget/TableWidget.cpp Views/TableWidget/TableWidget.h) 
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(DangerousObjectSearcher ${OpenCV_LIBS})
target_link_libraries(DangerousObjectSearcher Qt6::Widgets)