/**
 * @file test.cpp
 * @author Derek Larson
 * @brief Unit test file for functions_to_implement.cpp
 * 
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

TEST_CASE ("Split strings.", "[split]") {
  std::string s = "Here is a sentence.";

  SECTION ("Checking Split on a character") {
    std::vector<std::string> output = {"Here", "is", "a", "sentence."};
    REQUIRE( Split(s, " ") ==  output);
  }
  SECTION ("Checking Split on a word") {
    std::vector<std::string> output = {"Here ", " a sentence."};
    REQUIRE( Split(s, "is") == output);
  }
  SECTION ("Checking Split when separator is not present") {
    std::vector<std::string> expected = {"Here is a sentence."};
    REQUIRE( Split(s, "snail") == expected );
  }
  SECTION ("Checking Split when separator is the whole string") {
    std::string full = "Here is a sentence.";
    std::vector<std::string> expected = {"", ""};
    REQUIRE( Split(full, "Here is a sentence.") == expected );
  }
  SECTION ("Checking Split on an empty string") {
    std::vector<std::string> expected = {""};
    REQUIRE( Split("", " ") == expected );
  }
}

TEST_CASE ("Removing substrings.", "[removeAllSubstrings]") {
  std::string s = "Here is a sentence.";

  SECTION("Checking RemoveAllSubstrings on a single character") {
    REQUIRE( RemoveAllSubstrings(s, " ") == "Hereisasentence." );
  }
  SECTION("Checking RemoveAllSubstrings on a word") {
    REQUIRE( RemoveAllSubstrings(s, "is") == "Here  a sentence." );
  }
  SECTION("Checking RemoveAllSubstrings on multiple occurrences") {
    std::string substring = "potato, potato, potato";
    REQUIRE( RemoveAllSubstrings(substring, "potato") == ", , " );
  }
  SECTION("Checking RemoveAllSubstrings on a substring not present") {
    REQUIRE( RemoveAllSubstrings(s, "snail") == "Here is a sentence." );
  }
  SECTION("Checking RemoveAllSubstrings on the entire string") {
    REQUIRE( RemoveAllSubstrings(s, "Here is a sentence.") == "" );
  }
  SECTION("Checking RemoveAllSubstrings on an empty string") {
    std::string substring = "potato";
    REQUIRE( RemoveAllSubstrings("", substring) == "");
  }
}

TEST_CASE ("Removing first substring.", "[removeFirstSubstring]") {
  std::string s = "Here is a sentence.";

  SECTION("Checking RemoveFirstSubstring on a single character") {
    REQUIRE( RemoveFirstSubstring(s, " ") == "Hereis a sentence." );
  }
  SECTION("Checking RemoveFirstSubstring on a word") {
    REQUIRE( RemoveFirstSubstring(s, "is") == "Here  a sentence." );
  }
  SECTION("Checking RemoveFirstSubstring on multiple occurrences") {
    std::string repeated = "potato, potato, potato";
    REQUIRE( RemoveFirstSubstring(repeated, "potato") == ", potato, potato" );
  }
  SECTION("Checking RemoveFirstSubstring on a substring not present") {
    REQUIRE( RemoveFirstSubstring(s, "snail") == "Here is a sentence." );
  }
  SECTION("Checking RemoveFirstSubstring on the entire string") {
    REQUIRE( RemoveFirstSubstring(s, "Here is a sentence.") == "" );
  }
  SECTION("Checking RemoveFirstSubstring on an empty string") {
    REQUIRE( RemoveFirstSubstring("", "potato") == "" );
  }
}

TEST_CASE ("Joining a vector of strings.", "[join]") {
  std::vector<std::string> v = {"Here", "is", "a", "sentence."};

  SECTION("Checking Join with single character glue") {
    REQUIRE( Join(v, " ") == "Here is a sentence.");
  }
  SECTION("Chcking Join on an empty vector.")  {
    std::vector<std::string> s = {};
    REQUIRE ( Join(s, " ") == "");
  }
  SECTION("Checking Join without glue") {
    REQUIRE ( Join(v, "") == "Hereisasentence.");
  }
  SECTION("Checking Join with multi character glue") {
    REQUIRE ( Join(v, " snail ") == "Here snail is snail a snail sentence.");
  }
  SECTION("Checking Join with a single element vector") {
    std::vector<std::string> single = {"Hello"};
    REQUIRE( Join(single, " ") == "Hello" );
  }
  SECTION("Checking Join with empty strings in the vector") {
    std::vector<std::string> empties = {"", "", ""};
    REQUIRE( Join(empties, " ") == "  " );
  }
  SECTION("Checking Join with a single character glue and empty strings") {
    std::vector<std::string> mixed = {"Here", "", "sentence."};
    REQUIRE( Join(mixed, " ") == "Here  sentence." );
  }
}

TEST_CASE("Removing twos from an integer.", "[removetwos]") {

  SECTION("Checking RemoveTwos on a power of 2") {
    REQUIRE( RemoveTwos(16) == 1 );
  }
  SECTION("Checking RemoveTwos on an odd number") {
    REQUIRE( RemoveTwos(7) == 7 );
  }
  SECTION("Checking RemoveTwos on an even number with odd factor") {
    REQUIRE( RemoveTwos(26) == 13 );
  }
  SECTION("Checking RemoveTwos on multiple factors of 2") {
    REQUIRE( RemoveTwos(52) == 13 );
  }
  SECTION("Checking RemoveTwos on zero") {
    REQUIRE( RemoveTwos(0) == 0 );
  }
  SECTION("Checking RemoveTwos on 1") {
    REQUIRE( RemoveTwos(1) == 1 );
  }
  SECTION("Checking RemoveTwos on 2") {
    REQUIRE( RemoveTwos(2) == 1 );
  }
}

TEST_CASE ("Determining multiples of a number.", "[multiplesFilter]") {
  SECTION("Checking MultiplesFilter on a list of numbers") {
    std::vector<int> v = {1, 4, 3, 8, 5};
    std::vector<int> evens = {4, 8};
    REQUIRE( MultiplesFilter(v, 2) == evens);
  }
  SECTION("Checking MultiplesFilter on an empty vector") {
    std::vector<int> empty;
    REQUIRE( MultiplesFilter(empty, 5) == empty);
  }
  SECTION( "Checking MultiplesFilter with divides_by 1") {
    std::vector<int> v = {1, 4, 3, 8, 5};
    REQUIRE( MultiplesFilter(v, 1) == v);
  }
  SECTION("Checking MultiplesFilter with divides_by 0") {
    std::vector<int> v = {1, 4, 3, 8, 5};
    std::vector<int> empty;
    REQUIRE( MultiplesFilter(v, 0) == empty);
  }
  SECTION("Checking MultiplesFilter when no elements match") {
    std::vector<int> v2 = {1, 3, 5, 7};
    std::vector<int> empty;
    REQUIRE( MultiplesFilter(v2, 2) == empty );
  }
  SECTION("Checking MultiplesFilter when all elements match") {
    std::vector<int> v2 = {2, 4, 6, 8};
    REQUIRE( MultiplesFilter(v2, 2) == v2 );
  }
  SECTION("Checking MultiplesFilter with negative numbers") {
    std::vector<int> v2 = {-4, -3, -2, -1};
    std::vector<int> expected = {-4, -2};
    REQUIRE( MultiplesFilter(v2, 2) == expected );
  }
}

TEST_CASE("Creating an even mask from a vector of ints.", "[evenmask]") {

  SECTION("Checking EvenMask on a mixed vector") {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<bool> expected = {false, true, false, true, false};
    REQUIRE( EvenMask(input) == expected );
  }
  SECTION("Checking EvenMask on all even numbers") {
    std::vector<int> input = {2, 4, 6, 8};
    std::vector<bool> expected = {true, true, true, true};
    REQUIRE( EvenMask(input) == expected );
  }
  SECTION("Checking EvenMask on all odd numbers") {
    std::vector<int> input = {1, 3, 5, 7};
    std::vector<bool> expected = {false, false, false, false};
    REQUIRE( EvenMask(input) == expected );
  }
  SECTION("Checking EvenMask on an empty vector") {
    std::vector<int> input = {};
    std::vector<bool> expected = {};
    REQUIRE( EvenMask(input) == expected );
  }
  SECTION("Checking EvenMask on zero") {
    std::vector<int> input = {0};
    std::vector<bool> expected = {true};
    REQUIRE( EvenMask(input) == expected );
  }
  SECTION("Checking EvenMask on negative numbers") {
    std::vector<int> input = {-4, -3, -2, -1};
    std::vector<bool> expected = {true, false, true, false};
    REQUIRE( EvenMask(input) == expected );
  }
SECTION("Checking EvenMask output is same length as input") {
    std::vector<int> input = {1, 2, 3, 4, 5};
    REQUIRE( EvenMask(input).size() == input.size() );
  }
}