#pragma once

#include <odyssey/account_statistics/account_statistics_plugin.hpp>

#include <fc/api.hpp>

namespace odyssey{ namespace app {
   struct api_context;
} }

namespace odyssey { namespace account_statistics {

namespace detail
{
   class account_statistics_api_impl;
}

class account_statistics_api
{
   public:
      account_statistics_api( const odyssey::app::api_context& ctx );

      void on_api_startup();

   private:
      std::shared_ptr< detail::account_statistics_api_impl > _my;
};

} } // odyssey::account_statistics

FC_API( odyssey::account_statistics::account_statistics_api, )