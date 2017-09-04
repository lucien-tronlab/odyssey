#pragma once

#include <odyssey/chain/evaluator.hpp>

#include <odyssey/private_message/private_message_operations.hpp>
#include <odyssey/private_message/private_message_plugin.hpp>

namespace odyssey { namespace private_message {

DEFINE_PLUGIN_EVALUATOR( private_message_plugin, odyssey::private_message::private_message_plugin_operation, private_message )

} }
