file(GLOB HEADERS "include/odyssey/witness/*.hpp")

add_library( odyssey_witness
             witness_plugin.cpp
             witness_evaluators.cpp
             witness_operations.cpp
           )

target_link_libraries( odyssey_witness odyssey_chain odyssey_protocol odyssey_app )
target_include_directories( odyssey_witness
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   odyssey_witness

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
