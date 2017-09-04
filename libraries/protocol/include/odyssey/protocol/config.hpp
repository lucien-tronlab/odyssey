/*
 * Copyright (c) 2016 Odyssey, Inc., and contributors.
 */
#pragma once

#define ODYSSEY_BLOCKCHAIN_VERSION              ( version(0, 19, 2) )
#define ODYSSEY_BLOCKCHAIN_HARDFORK_VERSION     ( hardfork_version( ODYSSEY_BLOCKCHAIN_VERSION ) )

#ifdef IS_TEST_NET
#define ODYSSEY_INIT_PRIVATE_KEY                (fc::ecc::private_key::regenerate(fc::sha256::hash(std::string("init_key"))))
#define ODYSSEY_INIT_PUBLIC_KEY_STR             (std::string( odyssey::protocol::public_key_type(ODYSSEY_INIT_PRIVATE_KEY.get_public_key()) ))
#define ODYSSEY_CHAIN_ID                        (fc::sha256::hash("testnet"))

#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define ODYSSEY_SYMBOL  (uint64_t(3) | (uint64_t('T') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< ODYSSEY with 3 digits of precision
#define SBD_SYMBOL    (uint64_t(3) | (uint64_t('T') << 8) | (uint64_t('B') << 16) | (uint64_t('D') << 24) ) ///< Test Backed Dollars with 3 digits of precision
#define STMD_SYMBOL   (uint64_t(3) | (uint64_t('T') << 8) | (uint64_t('S') << 16) | (uint64_t('T') << 24) | (uint64_t('D') << 32) ) ///< Test Dollars with 3 digits of precision

#define ODYSSEY_SYMBOL                          "TEST"
#define ODYSSEY_ADDRESS_PREFIX                  "TST"

#define ODYSSEY_GENESIS_TIME                    (fc::time_point_sec(1451606400))
#define ODYSSEY_MINING_TIME                     (fc::time_point_sec(1451606400))
#define ODYSSEY_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define ODYSSEY_CASHOUT_WINDOW_SECONDS_PRE_HF12 (ODYSSEY_CASHOUT_WINDOW_SECONDS)
#define ODYSSEY_CASHOUT_WINDOW_SECONDS_PRE_HF17 (ODYSSEY_CASHOUT_WINDOW_SECONDS)
#define ODYSSEY_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define ODYSSEY_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define ODYSSEY_VOTE_CHANGE_LOCKOUT_PERIOD      (60*10) /// 10 minutes
#define ODYSSEY_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define ODYSSEY_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define ODYSSEY_ORIGINAL_MIN_ACCOUNT_CREATION_FEE 0
#define ODYSSEY_MIN_ACCOUNT_CREATION_FEE          0

#define ODYSSEY_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define ODYSSEY_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define ODYSSEY_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define ODYSSEY_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1
#else // IS LIVE ODYSSEY NETWORK

#define ODYSSEY_INIT_PUBLIC_KEY_STR             "STM8GC13uCZbP44HzMLV6zPZGwVQ8Nt4Kji8PapsPiNq1BK153XTX"
#define ODYSSEY_CHAIN_ID                        (odyssey::protocol::chain_id_type())
#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define ODYSSEY_SYMBOL  (uint64_t(3) | (uint64_t('S') << 8) | (uint64_t('T') << 16) | (uint64_t('E') << 24) | (uint64_t('E') << 32) | (uint64_t('M') << 40)) ///< ODYSSEY with 3 digits of precision
#define SBD_SYMBOL    (uint64_t(3) | (uint64_t('S') << 8) | (uint64_t('B') << 16) | (uint64_t('D') << 24) ) ///< ODYSSEY Backed Dollars with 3 digits of precision
#define STMD_SYMBOL   (uint64_t(3) | (uint64_t('S') << 8) | (uint64_t('T') << 16) | (uint64_t('M') << 24) | (uint64_t('D') << 32) ) ///< ODYSSEY Dollars with 3 digits of precision
#define ODYSSEY_SYMBOL                          "ODYSSEY"
#define ODYSSEY_ADDRESS_PREFIX                  "STM"

#define ODYSSEY_GENESIS_TIME                    (fc::time_point_sec(1458835200))
#define ODYSSEY_MINING_TIME                     (fc::time_point_sec(1458838800))
#define ODYSSEY_CASHOUT_WINDOW_SECONDS_PRE_HF12 (60*60*24)    /// 1 day
#define ODYSSEY_CASHOUT_WINDOW_SECONDS_PRE_HF17 (60*60*12)    /// 12 hours
#define ODYSSEY_CASHOUT_WINDOW_SECONDS          (60*60*24*7)  /// 7 days
#define ODYSSEY_SECOND_CASHOUT_WINDOW           (60*60*24*30) /// 30 days
#define ODYSSEY_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24*14) /// 2 weeks
#define ODYSSEY_VOTE_CHANGE_LOCKOUT_PERIOD      (60*60*2)     /// 2 hours
#define ODYSSEY_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define ODYSSEY_UPVOTE_LOCKOUT_HF17             (fc::hours(12))

#define ODYSSEY_ORIGINAL_MIN_ACCOUNT_CREATION_FEE  100000
#define ODYSSEY_MIN_ACCOUNT_CREATION_FEE           1

#define ODYSSEY_OWNER_AUTH_RECOVERY_PERIOD                  fc::days(30)
#define ODYSSEY_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::days(1)
#define ODYSSEY_OWNER_UPDATE_LIMIT                          fc::minutes(60)
#define ODYSSEY_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 3186477

#endif

#define ODYSSEY_BLOCK_INTERVAL                  3
#define ODYSSEY_BLOCKS_PER_YEAR                 (365*24*60*60/ODYSSEY_BLOCK_INTERVAL)
#define ODYSSEY_BLOCKS_PER_DAY                  (24*60*60/ODYSSEY_BLOCK_INTERVAL)
#define ODYSSEY_START_VESTING_BLOCK             (ODYSSEY_BLOCKS_PER_DAY * 7)
#define ODYSSEY_START_MINER_VOTING_BLOCK        (ODYSSEY_BLOCKS_PER_DAY * 30)

#define ODYSSEY_INIT_MINER_NAME                 "initminer"
#define ODYSSEY_NUM_INIT_MINERS                 1
#define ODYSSEY_INIT_TIME                       (fc::time_point_sec());

#define ODYSSEY_MAX_WITNESSES                   21

#define ODYSSEY_MAX_VOTED_WITNESSES_HF0         19
#define ODYSSEY_MAX_MINER_WITNESSES_HF0         1
#define ODYSSEY_MAX_RUNNER_WITNESSES_HF0        1

#define ODYSSEY_MAX_VOTED_WITNESSES_HF17        20
#define ODYSSEY_MAX_MINER_WITNESSES_HF17        0
#define ODYSSEY_MAX_RUNNER_WITNESSES_HF17       1

#define ODYSSEY_HARDFORK_REQUIRED_WITNESSES     17 // 17 of the 21 dpos witnesses (20 elected and 1 virtual time) required for hardfork. This guarantees 75% participation on all subsequent rounds.
#define ODYSSEY_MAX_TIME_UNTIL_EXPIRATION       (60*60) // seconds,  aka: 1 hour
#define ODYSSEY_MAX_MEMO_SIZE                   2048
#define ODYSSEY_MAX_PROXY_RECURSION_DEPTH       4
#define ODYSSEY_VESTING_WITHDRAW_INTERVALS_PRE_HF_16 104
#define ODYSSEY_VESTING_WITHDRAW_INTERVALS      13
#define ODYSSEY_VESTING_WITHDRAW_INTERVAL_SECONDS (60*60*24*7) /// 1 week per interval
#define ODYSSEY_MAX_WITHDRAW_ROUTES             10
#define ODYSSEY_SAVINGS_WITHDRAW_TIME        	(fc::days(3))
#define ODYSSEY_SAVINGS_WITHDRAW_REQUEST_LIMIT  100
#define ODYSSEY_VOTE_REGENERATION_SECONDS       (5*60*60*24) // 5 day
#define ODYSSEY_MAX_VOTE_CHANGES                5
#define ODYSSEY_REVERSE_AUCTION_WINDOW_SECONDS  (60*30) /// 30 minutes
#define ODYSSEY_MIN_VOTE_INTERVAL_SEC           3
#define ODYSSEY_VOTE_DUST_THRESHOLD             (50000000)

#define ODYSSEY_MIN_ROOT_COMMENT_INTERVAL       (fc::seconds(60*5)) // 5 minutes
#define ODYSSEY_MIN_REPLY_INTERVAL              (fc::seconds(20)) // 20 seconds
#define ODYSSEY_POST_AVERAGE_WINDOW             (60*60*24u) // 1 day
#define ODYSSEY_POST_MAX_BANDWIDTH              (4*ODYSSEY_100_PERCENT) // 2 posts per 1 days, average 1 every 12 hours
#define ODYSSEY_POST_WEIGHT_CONSTANT            (uint64_t(ODYSSEY_POST_MAX_BANDWIDTH) * ODYSSEY_POST_MAX_BANDWIDTH)

#define ODYSSEY_MAX_ACCOUNT_WITNESS_VOTES       30

#define ODYSSEY_100_PERCENT                     10000
#define ODYSSEY_1_PERCENT                       (ODYSSEY_100_PERCENT/100)
#define ODYSSEY_1_TENTH_PERCENT                 (ODYSSEY_100_PERCENT/1000)
#define ODYSSEY_DEFAULT_SBD_INTEREST_RATE       (10*ODYSSEY_1_PERCENT) ///< 10% APR

#define ODYSSEY_INFLATION_RATE_START_PERCENT    (978) // Fixes block 7,000,000 to 9.5%
#define ODYSSEY_INFLATION_RATE_STOP_PERCENT     (95) // 0.95%
#define ODYSSEY_INFLATION_NARROWING_PERIOD      (250000) // Narrow 0.01% every 250k blocks
#define ODYSSEY_CONTENT_REWARD_PERCENT          (75*ODYSSEY_1_PERCENT) //75% of inflation, 7.125% inflation
#define ODYSSEY_VESTING_FUND_PERCENT            (15*ODYSSEY_1_PERCENT) //15% of inflation, 1.425% inflation

#define ODYSSEY_MINER_PAY_PERCENT               (ODYSSEY_1_PERCENT) // 1%
#define ODYSSEY_MIN_RATION                      100000
#define ODYSSEY_MAX_RATION_DECAY_RATE           (1000000)
#define ODYSSEY_FREE_TRANSACTIONS_WITH_NEW_ACCOUNT 100

#define ODYSSEY_BANDWIDTH_AVERAGE_WINDOW_SECONDS (60*60*24*7) ///< 1 week
#define ODYSSEY_BANDWIDTH_PRECISION             (uint64_t(1000000)) ///< 1 million
#define ODYSSEY_MAX_COMMENT_DEPTH_PRE_HF17      6
#define ODYSSEY_MAX_COMMENT_DEPTH               0xffff // 64k
#define ODYSSEY_SOFT_MAX_COMMENT_DEPTH          0xff // 255

#define ODYSSEY_MAX_RESERVE_RATIO               (20000)

#define ODYSSEY_CREATE_ACCOUNT_WITH_ODYSSEY_MODIFIER 30
#define ODYSSEY_CREATE_ACCOUNT_DELEGATION_RATIO    5
#define ODYSSEY_CREATE_ACCOUNT_DELEGATION_TIME     fc::days(30)

#define ODYSSEY_MINING_REWARD                   asset( 1000, ODYSSEY_SYMBOL )
#define ODYSSEY_EQUIHASH_N                      140
#define ODYSSEY_EQUIHASH_K                      6

#define ODYSSEY_LIQUIDITY_TIMEOUT_SEC           (fc::seconds(60*60*24*7)) // After one week volume is set to 0
#define ODYSSEY_MIN_LIQUIDITY_REWARD_PERIOD_SEC (fc::seconds(60)) // 1 minute required on books to receive volume
#define ODYSSEY_LIQUIDITY_REWARD_PERIOD_SEC     (60*60)
#define ODYSSEY_LIQUIDITY_REWARD_BLOCKS         (ODYSSEY_LIQUIDITY_REWARD_PERIOD_SEC/ODYSSEY_BLOCK_INTERVAL)
#define ODYSSEY_MIN_LIQUIDITY_REWARD            (asset( 1000*ODYSSEY_LIQUIDITY_REWARD_BLOCKS, ODYSSEY_SYMBOL )) // Minumum reward to be paid out to liquidity providers
#define ODYSSEY_MIN_CONTENT_REWARD              ODYSSEY_MINING_REWARD
#define ODYSSEY_MIN_CURATE_REWARD               ODYSSEY_MINING_REWARD
#define ODYSSEY_MIN_PRODUCER_REWARD             ODYSSEY_MINING_REWARD
#define ODYSSEY_MIN_POW_REWARD                  ODYSSEY_MINING_REWARD

#define ODYSSEY_ACTIVE_CHALLENGE_FEE            asset( 2000, ODYSSEY_SYMBOL )
#define ODYSSEY_OWNER_CHALLENGE_FEE             asset( 30000, ODYSSEY_SYMBOL )
#define ODYSSEY_ACTIVE_CHALLENGE_COOLDOWN       fc::days(1)
#define ODYSSEY_OWNER_CHALLENGE_COOLDOWN        fc::days(1)

#define ODYSSEY_POST_REWARD_FUND_NAME           ("post")
#define ODYSSEY_COMMENT_REWARD_FUND_NAME        ("comment")
#define ODYSSEY_RECENT_RSHARES_DECAY_RATE_HF17  (fc::days(30))
#define ODYSSEY_RECENT_RSHARES_DECAY_RATE_HF19  (fc::days(15))
#define ODYSSEY_CONTENT_CONSTANT_HF0            (uint128_t(uint64_t(2000000000000ll)))
// note, if redefining these constants make sure calculate_claims doesn't overflow

// 5ccc e802 de5f
// int(expm1( log1p( 1 ) / BLOCKS_PER_YEAR ) * 2**ODYSSEY_APR_PERCENT_SHIFT_PER_BLOCK / 100000 + 0.5)
// we use 100000 here instead of 10000 because we end up creating an additional 9x for vesting
#define ODYSSEY_APR_PERCENT_MULTIPLY_PER_BLOCK          ( (uint64_t( 0x5ccc ) << 0x20) \
                                                        | (uint64_t( 0xe802 ) << 0x10) \
                                                        | (uint64_t( 0xde5f )        ) \
                                                        )
// chosen to be the maximal value such that ODYSSEY_APR_PERCENT_MULTIPLY_PER_BLOCK * 2**64 * 100000 < 2**128
#define ODYSSEY_APR_PERCENT_SHIFT_PER_BLOCK             87

#define ODYSSEY_APR_PERCENT_MULTIPLY_PER_ROUND          ( (uint64_t( 0x79cc ) << 0x20 ) \
                                                        | (uint64_t( 0xf5c7 ) << 0x10 ) \
                                                        | (uint64_t( 0x3480 )         ) \
                                                        )

#define ODYSSEY_APR_PERCENT_SHIFT_PER_ROUND             83

// We have different constants for hourly rewards
// i.e. hex(int(math.expm1( math.log1p( 1 ) / HOURS_PER_YEAR ) * 2**ODYSSEY_APR_PERCENT_SHIFT_PER_HOUR / 100000 + 0.5))
#define ODYSSEY_APR_PERCENT_MULTIPLY_PER_HOUR           ( (uint64_t( 0x6cc1 ) << 0x20) \
                                                        | (uint64_t( 0x39a1 ) << 0x10) \
                                                        | (uint64_t( 0x5cbd )        ) \
                                                        )

// chosen to be the maximal value such that ODYSSEY_APR_PERCENT_MULTIPLY_PER_HOUR * 2**64 * 100000 < 2**128
#define ODYSSEY_APR_PERCENT_SHIFT_PER_HOUR              77

// These constants add up to GRAPHENE_100_PERCENT.  Each GRAPHENE_1_PERCENT is equivalent to 1% per year APY
// *including the corresponding 9x vesting rewards*
#define ODYSSEY_CURATE_APR_PERCENT              3875
#define ODYSSEY_CONTENT_APR_PERCENT             3875
#define ODYSSEY_LIQUIDITY_APR_PERCENT            750
#define ODYSSEY_PRODUCER_APR_PERCENT             750
#define ODYSSEY_POW_APR_PERCENT                  750

#define ODYSSEY_MIN_PAYOUT_SBD                  (asset(20,SBD_SYMBOL))

#define ODYSSEY_SBD_STOP_PERCENT                (5*ODYSSEY_1_PERCENT ) // Stop printing SBD at 5% Market Cap
#define ODYSSEY_SBD_START_PERCENT               (2*ODYSSEY_1_PERCENT) // Start reducing printing of SBD at 2% Market Cap

#define ODYSSEY_MIN_ACCOUNT_NAME_LENGTH          3
#define ODYSSEY_MAX_ACCOUNT_NAME_LENGTH         16

#define ODYSSEY_MIN_PERMLINK_LENGTH             0
#define ODYSSEY_MAX_PERMLINK_LENGTH             256
#define ODYSSEY_MAX_WITNESS_URL_LENGTH          2048

#define ODYSSEY_INIT_SUPPLY                     int64_t(0)
#define ODYSSEY_MAX_SHARE_SUPPLY                int64_t(1000000000000000ll)
#define ODYSSEY_MAX_SIG_CHECK_DEPTH             2

#define ODYSSEY_MIN_TRANSACTION_SIZE_LIMIT      1024
#define ODYSSEY_SECONDS_PER_YEAR                (uint64_t(60*60*24*365ll))

#define ODYSSEY_SBD_INTEREST_COMPOUND_INTERVAL_SEC  (60*60*24*30)
#define ODYSSEY_MAX_TRANSACTION_SIZE            (1024*64)
#define ODYSSEY_MIN_BLOCK_SIZE_LIMIT            (ODYSSEY_MAX_TRANSACTION_SIZE)
#define ODYSSEY_MAX_BLOCK_SIZE                  (ODYSSEY_MAX_TRANSACTION_SIZE*ODYSSEY_BLOCK_INTERVAL*2000)
#define ODYSSEY_MIN_BLOCK_SIZE                  115
#define ODYSSEY_BLOCKS_PER_HOUR                 (60*60/ODYSSEY_BLOCK_INTERVAL)
#define ODYSSEY_FEED_INTERVAL_BLOCKS            (ODYSSEY_BLOCKS_PER_HOUR)
#define ODYSSEY_FEED_HISTORY_WINDOW_PRE_HF_16   (24*7) /// 7 days * 24 hours per day
#define ODYSSEY_FEED_HISTORY_WINDOW             (12*7) // 3.5 days
#define ODYSSEY_MAX_FEED_AGE_SECONDS            (60*60*24*7) // 7 days
#define ODYSSEY_MIN_FEEDS                       (ODYSSEY_MAX_WITNESSES/3) /// protects the network from conversions before price has been established
#define ODYSSEY_CONVERSION_DELAY_PRE_HF_16      (fc::days(7))
#define ODYSSEY_CONVERSION_DELAY                (fc::hours(ODYSSEY_FEED_HISTORY_WINDOW)) //3.5 day conversion

#define ODYSSEY_MIN_UNDO_HISTORY                10
#define ODYSSEY_MAX_UNDO_HISTORY                10000

#define ODYSSEY_MIN_TRANSACTION_EXPIRATION_LIMIT (ODYSSEY_BLOCK_INTERVAL * 5) // 5 transactions per block
#define ODYSSEY_BLOCKCHAIN_PRECISION            uint64_t( 1000 )

#define ODYSSEY_BLOCKCHAIN_PRECISION_DIGITS     3
#define ODYSSEY_MAX_INSTANCE_ID                 (uint64_t(-1)>>16)
/** NOTE: making this a power of 2 (say 2^15) would greatly accelerate fee calcs */
#define ODYSSEY_MAX_AUTHORITY_MEMBERSHIP        10
#define ODYSSEY_MAX_ASSET_WHITELIST_AUTHORITIES 10
#define ODYSSEY_MAX_URL_LENGTH                  127

#define ODYSSEY_IRREVERSIBLE_THRESHOLD          (75 * ODYSSEY_1_PERCENT)

#define VIRTUAL_SCHEDULE_LAP_LENGTH  ( fc::uint128(uint64_t(-1)) )
#define VIRTUAL_SCHEDULE_LAP_LENGTH2 ( fc::uint128::max_value() )

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the current witnesses
#define ODYSSEY_MINER_ACCOUNT                   "miners"
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define ODYSSEY_NULL_ACCOUNT                    "null"
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define ODYSSEY_TEMP_ACCOUNT                    "temp"
/// Represents the canonical account for specifying you will vote for directly (as opposed to a proxy)
#define ODYSSEY_PROXY_TO_SELF_ACCOUNT           ""
/// Represents the canonical root post parent account
#define ODYSSEY_ROOT_POST_PARENT                (account_name_type())
///@}
