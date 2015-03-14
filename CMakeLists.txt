project(cpp_01)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
find_package(EXPAT)
set(CMAKE_BUILD_TYPE "Debug")
add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${EXPAT_LIBRARIES})

