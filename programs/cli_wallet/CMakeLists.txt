add_executable( cli_wallet main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling cli_wallet with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( ODYSSEY_STATIC_BUILD )
   # I don't know why odyssey_app is required twice in the following line, I just know the linker breaks if it isn't.
   target_link_libraries( cli_wallet PRIVATE
                          "-static-libstdc++ -static-libgcc -lreadline"
                          odyssey_app graphene_net odyssey_chain odyssey_protocol graphene_utilities odyssey_wallet odyssey_private_message odyssey_app odyssey_follow fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )
else( ODYSSEY_STATIC_BUILD )
   target_link_libraries( cli_wallet PRIVATE
                          odyssey_app graphene_net odyssey_chain odyssey_protocol graphene_utilities odyssey_wallet odyssey_private_message odyssey_app odyssey_follow fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )
endif( ODYSSEY_STATIC_BUILD )

if(MSVC)
  set_source_files_properties( main.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   cli_wallet

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
