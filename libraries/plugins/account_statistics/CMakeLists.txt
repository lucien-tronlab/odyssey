file(GLOB HEADERS "include/odyssey/account_statistics/*.hpp")

add_library( odyssey_account_statistics
             account_statistics_plugin.cpp
             account_statistics_api.cpp
           )

target_link_libraries( odyssey_account_statistics odyssey_chain odyssey_protocol odyssey_app )
target_include_directories( odyssey_account_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   odyssey_account_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)