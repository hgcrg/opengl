project(cairo_freeimage_01)
aux_source_directory(. SRC)
add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} libfreeimage.so libcairo.so)
