file(GLOB HEADERS "include/odyssey/plugins/raw_block/*.hpp")

add_library( odyssey_raw_block
             ${HEADERS}
             raw_block_plugin.cpp
             raw_block_api.cpp
           )

target_link_libraries( odyssey_raw_block odyssey_app odyssey_chain odyssey_protocol fc )
target_include_directories( odyssey_raw_block
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
