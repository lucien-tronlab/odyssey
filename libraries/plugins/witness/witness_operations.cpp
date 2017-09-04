#include <odyssey/witness/witness_operations.hpp>

#include <odyssey/protocol/operation_util_impl.hpp>

namespace odyssey { namespace witness {

void enable_content_editing_operation::validate()const
{
   chain::validate_account_name( account );
}

} } // odyssey::witness

DEFINE_OPERATION_TYPE( odyssey::witness::witness_plugin_operation )
