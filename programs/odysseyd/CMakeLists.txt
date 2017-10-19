add_executable( odysseyd main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling odysseyd with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( ODYSSEY_STATIC_BUILD )
   target_link_libraries( odysseyd PRIVATE
      "-static-libstdc++ -static-libgcc"
      odyssey_plugins
      odyssey_mf_plugins
      odyssey_app
      odyssey_witness
      odyssey_account_history
      odyssey_chain
      odyssey_protocol
      fc
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
else( ODYSSEY_STATIC_BUILD )
   target_link_libraries( odysseyd PRIVATE
      odyssey_plugins
      odyssey_mf_plugins
      odyssey_app
      odyssey_witness
      odyssey_account_history
      odyssey_chain
      odyssey_protocol
      fc
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
endif( ODYSSEY_STATIC_BUILD )

install( TARGETS
   odysseyd

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
