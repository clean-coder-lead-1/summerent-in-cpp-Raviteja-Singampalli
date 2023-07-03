#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to test low limit") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to test normal limit") {
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
}
TEST_CASE("infers the breach according to test high limit") {
  REQUIRE(inferBreach(35, 20, 30) == TOO_HIGH);
}

TEST_CASE("clasify temprature breach test") {
  REQUIRE( classifyTemperatureBreach(PASSIVE_COOLING, 30) == NORMAL);
}

TEST_CASE("clasify temprature breach test1") {
  REQUIRE( classifyTemperatureBreach(PASSIVE_COOLING, 40) == TOO_HIGH);
}
TEST_CASE("clasify temprature breach test2") {
  REQUIRE( classifyTemperatureBreach(HI_ACTIVE_COOLING, 40) == NORMAL);
}

TEST_CASE("clasify temprature breach test3") {
  REQUIRE( classifyTemperatureBreach(HI_ACTIVE_COOLING, 48) == TOO_HIGH);
}
