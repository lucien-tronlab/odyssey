file(GLOB HEADERS "include/odyssey/blockchain_statistics/*.hpp")

add_library( odyssey_blockchain_statistics
             blockchain_statistics_plugin.cpp
             blockchain_statistics_api.cpp
           )

target_link_libraries( odyssey_blockchain_statistics odyssey_chain odyssey_protocol odyssey_app )
target_include_directories( odyssey_blockchain_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   odyssey_blockchain_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)