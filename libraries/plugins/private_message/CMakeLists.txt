file(GLOB HEADERS "include/odyssey/private_message/*.hpp")

add_library( odyssey_private_message
             private_message_plugin.cpp
           )

target_link_libraries( odyssey_private_message odyssey_chain odyssey_protocol odyssey_app )
target_include_directories( odyssey_private_message
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   odyssey_private_message

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
