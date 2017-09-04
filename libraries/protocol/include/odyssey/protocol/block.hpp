#pragma once
#include <odyssey/protocol/block_header.hpp>
#include <odyssey/protocol/transaction.hpp>

namespace odyssey { namespace protocol {

   struct signed_block : public signed_block_header
   {
      checksum_type calculate_merkle_root()const;
      vector<signed_transaction> transactions;
   };

} } // odyssey::protocol

FC_REFLECT_DERIVED( odyssey::protocol::signed_block, (odyssey::protocol::signed_block_header), (transactions) )
