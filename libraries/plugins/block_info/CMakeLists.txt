file(GLOB HEADERS "include/odyssey/plugins/block_info/*.hpp")

add_library( odyssey_block_info
             ${HEADERS}
             block_info_plugin.cpp
             block_info_api.cpp
           )

target_link_libraries( odyssey_block_info odyssey_app odyssey_chain odyssey_protocol fc )
target_include_directories( odyssey_block_info
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
