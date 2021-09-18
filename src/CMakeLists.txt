aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRCS)

target_include_directories(${PROJECT_NAME} PUBLIC includes)
target_include_directories(${PROJECT_NAME} PUBLIC grass_tile)
target_sources(${PROJECT_NAME} PUBLIC ${SRCS} 
    grass_tile/grass_tile.c
    dirt_tile/dirt_tile.c
    dirt_border_up_tile/dirt_border_up_tile.c
    fairy_character/fairy_character.c
    dirt_border_down_tile/dirt_border_down_tile.c)
