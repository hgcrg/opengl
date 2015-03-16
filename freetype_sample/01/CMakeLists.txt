project(01_freetype_qt)
aux_source_directory(. SRC)

include(${QT_USE_FILE})
qt4_wrap_cpp(MOCS Widget.h)
add_executable(${PROJECT_NAME} ${SRC} ${MOCS})

target_link_libraries(${PROJECT_NAME}
                      ${GLUT_LIBRARIES}
                      ${FREETYPE_LIBRARIES}
                      ${OPENGL_LIBRARIES}
                      ${QT_LIBRARIES}
                      ${GLEW_LIBRARIES})
