file(GLOB HEADERS "include/odyssey/market_history/*.hpp")

add_library( odyssey_market_history
             market_history_plugin.cpp
             market_history_api.cpp
           )

target_link_libraries( odyssey_market_history odyssey_chain odyssey_protocol odyssey_app )
target_include_directories( odyssey_market_history
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   odyssey_market_history

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)