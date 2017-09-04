file(GLOB HEADERS "include/odyssey/follow/*.hpp")

add_library( odyssey_follow
             follow_plugin.cpp
             follow_api.cpp
             follow_operations.cpp
             follow_evaluators.cpp
           )

target_link_libraries( odyssey_follow odyssey_chain odyssey_protocol odyssey_app )
target_include_directories( odyssey_follow
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   odyssey_follow

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
