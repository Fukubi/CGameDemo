aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRCS)

target_include_directories(${PROJECT_NAME} PUBLIC includes)
target_sources(${PROJECT_NAME} PUBLIC ${SRCS})
