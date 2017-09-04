#include <odyssey/follow/follow_operations.hpp>

#include <odyssey/protocol/operation_util_impl.hpp>

namespace odyssey { namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } //odyssey::follow

DEFINE_OPERATION_TYPE( odyssey::follow::follow_plugin_operation )
