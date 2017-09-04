file(GLOB HEADERS "include/odyssey/tags/*.hpp")

add_library( odyssey_tags
             tags_plugin.cpp )

target_link_libraries( odyssey_tags odyssey_chain odyssey_protocol odyssey_app )
target_include_directories( odyssey_tags
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   odyssey_tags

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
