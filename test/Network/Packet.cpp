#include <SFML/Network.hpp>

#include <doctest/doctest.h>

#include <limits>

template <typename IntegerType>
static void testPacketStreamOperators(IntegerType expected)
{
    sf::Packet packet;
    packet << expected;
    IntegerType received;
    packet >> received;
    CHECK(expected == received);
}

TEST_CASE("sf::Packet class - [network]")
{
    SUBCASE("Stream operators")
    {
        SUBCASE("std::int8_t")
        {
            testPacketStreamOperators(std::int8_t(0));
            testPacketStreamOperators(std::int8_t(1));
            testPacketStreamOperators(std::numeric_limits<std::int8_t>::min());
            testPacketStreamOperators(std::numeric_limits<std::int8_t>::max());
        }

        SUBCASE("std::int16_t")
        {
            testPacketStreamOperators(std::int16_t(0));
            testPacketStreamOperators(std::int16_t(1));
            testPacketStreamOperators(std::numeric_limits<std::int16_t>::min());
            testPacketStreamOperators(std::numeric_limits<std::int16_t>::max());
        }

        SUBCASE("std::int32_t")
        {
            testPacketStreamOperators(std::int32_t(0));
            testPacketStreamOperators(std::int32_t(1));
            testPacketStreamOperators(std::numeric_limits<std::int32_t>::min());
            testPacketStreamOperators(std::numeric_limits<std::int32_t>::max());
        }

        SUBCASE("Int64")
        {
            testPacketStreamOperators(sf::Int64(0));
            testPacketStreamOperators(sf::Int64(1));
            testPacketStreamOperators(std::numeric_limits<sf::Int64>::min());
            testPacketStreamOperators(std::numeric_limits<sf::Int64>::max());
        }
    }
}