#pragma once

#include <odyssey/chain/util/asset.hpp>
#include <odyssey/chain/odyssey_objects.hpp>

#include <odyssey/protocol/asset.hpp>
#include <odyssey/protocol/config.hpp>
#include <odyssey/protocol/types.hpp>

#include <fc/reflect/reflect.hpp>

#include <fc/uint128.hpp>

namespace odyssey { namespace chain { namespace util {

using odyssey::protocol::asset;
using odyssey::protocol::price;
using odyssey::protocol::share_type;

using fc::uint128_t;

struct comment_reward_context
{
   share_type rshares;
   uint16_t   reward_weight = 0;
   asset      max_sbd;
   uint128_t  total_reward_shares2;
   asset      total_reward_fund_odyssey;
   price      current_odyssey_price;
   curve_id   reward_curve = quadratic;
   uint128_t  content_constant = ODYSSEY_CONTENT_CONSTANT_HF0;
};

uint64_t get_rshare_reward( const comment_reward_context& ctx );

inline uint128_t get_content_constant_s()
{
   return ODYSSEY_CONTENT_CONSTANT_HF0; // looking good for posters
}

uint128_t evaluate_reward_curve( const uint128_t& rshares, const curve_id& curve = quadratic, const uint128_t& content_constant = ODYSSEY_CONTENT_CONSTANT_HF0 );

inline bool is_comment_payout_dust( const price& p, uint64_t odyssey_payout )
{
   return to_sbd( p, asset( odyssey_payout, ODYSSEY_SYMBOL ) ) < ODYSSEY_MIN_PAYOUT_SBD;
}

} } } // odyssey::chain::util

FC_REFLECT( odyssey::chain::util::comment_reward_context,
   (rshares)
   (reward_weight)
   (max_sbd)
   (total_reward_shares2)
   (total_reward_fund_odyssey)
   (current_odyssey_price)
   (reward_curve)
   (content_constant)
   )
