project(cpp_01)
cmake_minimum_required(VERSION 2.8)

find_package(Freetype)
find_package(OpenGL)
find_package(GLEW)
find_package(Qt4 REQUIRED QtCore QtGui QtOpenGL)
find_package(GDAL)
#find_package(OpenSceneGraph REQUIRED osg osgViewer osgGA osgDB)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE "Debug")
INCLUDE_DIRECTORIES("/usr/include/freetype")
#add_subdirectory(freetype_sample)
#add_subdirectory(cairo_sample)
add_subdirectory(x11_sample)
add_subdirectory(ogr_sample)
#add_subdirectory(qt_sample)
