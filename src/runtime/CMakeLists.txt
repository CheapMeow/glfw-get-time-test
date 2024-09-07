set(RUNTIME_HEADER_FILES
    "macro.h"
    runtime.h
    time_utils.h)
set(RUNTIME_SOURCE_FILES
    runtime.cpp)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${RUNTIME_HEADER_FILES}
                                                      ${RUNTIME_SOURCE_FILES})

add_library(${RUNTIME_NAME} SHARED ${RUNTIME_HEADER_FILES}
                                   ${RUNTIME_SOURCE_FILES})

set_target_properties(${RUNTIME_NAME} PROPERTIES CXX_STANDARD 20)
set_target_properties(${RUNTIME_NAME} PROPERTIES FOLDER "Engine")

target_compile_definitions(${RUNTIME_NAME} PRIVATE LIBRARY_EXPORTS)

target_include_directories(${RUNTIME_NAME} PUBLIC ${SRC_ROOT_DIR}/runtime)

target_link_libraries(${RUNTIME_NAME} PUBLIC glfw)
target_include_directories(${RUNTIME_NAME}
                           PUBLIC ${3RD_PARTY_ROOT_DIR}/glfw/include)