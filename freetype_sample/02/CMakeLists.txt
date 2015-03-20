project(02_freetype)
aux_source_directory(. SRC)


add_executable(${PROJECT_NAME} ${SRC} )

target_link_libraries(${PROJECT_NAME}
                      ${GLUT_LIBRARIES}
                      ${FREETYPE_LIBRARIES}
                      ${OPENGL_LIBRARIES}
                      ${OPENSCENEGRAPH_LIBRARIES}
                      ${GLEW_LIBRARIES}
                      libfreeimage.so
                      )
