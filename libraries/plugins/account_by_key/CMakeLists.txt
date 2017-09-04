file(GLOB HEADERS "include/odyssey/account_by_key/*.hpp")

add_library( odyssey_account_by_key
             account_by_key_plugin.cpp
             account_by_key_api.cpp
           )

target_link_libraries( odyssey_account_by_key odyssey_chain odyssey_protocol odyssey_app )
target_include_directories( odyssey_account_by_key
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   odyssey_account_by_key

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
