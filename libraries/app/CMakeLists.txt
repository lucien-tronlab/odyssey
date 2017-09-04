file(GLOB HEADERS "include/odyssey/app/*.hpp")

add_library( odyssey_app
             database_api.cpp
             api.cpp
             application.cpp
             impacted.cpp
             plugin.cpp
             ${HEADERS}
           )

target_link_libraries( odyssey_app odyssey_chain odyssey_protocol odyssey_tags odyssey_follow odyssey_witness odyssey_mf_plugins fc graphene_net graphene_utilities )
target_include_directories( odyssey_app
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( application.cpp api.cpp database_api.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

INSTALL( TARGETS
   odyssey_app

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/odyssey/app" )
