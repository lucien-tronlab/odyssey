
#pragma once

#include <memory>
#include <string>
#include <vector>

namespace odyssey { namespace app {

class abstract_plugin;
class application;

} }

namespace odyssey { namespace plugin {

void initialize_plugin_factories();
std::shared_ptr< odyssey::app::abstract_plugin > create_plugin( const std::string& name, odyssey::app::application* app );
std::vector< std::string > get_available_plugins();

} }
