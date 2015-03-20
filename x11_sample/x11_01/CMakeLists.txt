project(x11_01)
aux_source_directory(. SRC)
add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} libX11.so libGL.so libGLU.so)
