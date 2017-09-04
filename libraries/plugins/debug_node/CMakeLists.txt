file(GLOB HEADERS "include/odyssey/plugins/debug_node/*.hpp")

add_library( odyssey_debug_node
             ${HEADERS}
             debug_node_plugin.cpp
             debug_node_api.cpp
           )

target_link_libraries( odyssey_debug_node odyssey_app odyssey_chain odyssey_protocol fc )
target_include_directories( odyssey_debug_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS odyssey_debug_node
         RUNTIME DESTINATION bin
         LIBRARY DESTINATION lib
         ARCHIVE DESTINATION lib
       )
INSTALL( FILES ${HEADERS} DESTINATION "include/odyssey/plugins/debug_node" )
