file(GLOB HEADERS "include/odyssey/account_history/*.hpp")

add_library( odyssey_account_history
             account_history_plugin.cpp
           )

target_link_libraries( odyssey_account_history odyssey_chain odyssey_protocol odyssey_app )
target_include_directories( odyssey_account_history
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   odyssey_account_history

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
