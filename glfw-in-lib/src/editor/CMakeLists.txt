set(EDITOR_HEADER_FILES "")
set(EDITOR_SOURCE_FILES
    editor.cpp)

add_executable(${EDITOR_NAME} ${EDITOR_HEADER_FILES} ${EDITOR_SOURCE_FILES})

set_target_properties(${EDITOR_NAME} PROPERTIES CXX_STANDARD 20)

target_include_directories(${EDITOR_NAME} PUBLIC ${SRC_ROOT_DIR}
                                                 ${SRC_ROOT_DIR}/editor)

target_link_libraries(${EDITOR_NAME} PUBLIC ${RUNTIME_NAME})
