#pragma once

#include <odyssey/protocol/asset.hpp>

namespace odyssey { namespace chain { namespace util {

using odyssey::protocol::asset;
using odyssey::protocol::price;

inline asset to_sbd( const price& p, const asset& odyssey )
{
   FC_ASSERT( odyssey.symbol == ODYSSEY_SYMBOL );
   if( p.is_null() )
      return asset( 0, SBD_SYMBOL );
   return odyssey * p;
}

inline asset to_odyssey( const price& p, const asset& sbd )
{
   FC_ASSERT( sbd.symbol == SBD_SYMBOL );
   if( p.is_null() )
      return asset( 0, ODYSSEY_SYMBOL );
   return sbd * p;
}

} } }
