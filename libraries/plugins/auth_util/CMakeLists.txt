file(GLOB HEADERS "include/odyssey/plugins/auth_util/*.hpp")

add_library( odyssey_auth_util
             ${HEADERS}
             auth_util_plugin.cpp
             auth_util_api.cpp
           )

target_link_libraries( odyssey_auth_util odyssey_app odyssey_chain odyssey_protocol fc )
target_include_directories( odyssey_auth_util
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
