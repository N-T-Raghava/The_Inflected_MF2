#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "mf2.h"

TEST_CASE("Basic formatting") {
    MessageFormat2 mf("{name} is {age} years old");
    std::unordered_map<std::string, std::variant<int, std::string, std::vector<std::string>>> args{
        {"name", "Alice"},
        {"age", 30}
    };
    REQUIRE(mf.format(args) == "Alice is 30 years old");
}

TEST_CASE("List formatting") {
    MessageFormat2 mf("List: {items}");
    std::unordered_map<std::string, std::variant<int, std::string, std::vector<std::string>>> args1{
        {"items", std::vector<std::string>{"apple"}}
    };
    REQUIRE(mf.format(args1) == "List: apple");

    std::unordered_map<std::string, std::variant<int, std::string, std::vector<std::string>>> args2{
        {"items", std::vector<std::string>{"apple", "banana"}}
    };
    REQUIRE(mf.format(args2) == "List: apple and banana");

    std::unordered_map<std::string, std::variant<int, std::string, std::vector<std::string>>> args3{
        {"items", std::vector<std::string>{"apple", "banana", "orange"}}
    };
    REQUIRE(mf.format(args3) == "List: apple, banana, and orange");
}

TEST_CASE("Pluralization") {
    MessageFormat2 mf("{count} {item}");
    REQUIRE(mf.pluralize(1, "apple", "apples") == "apple");
    REQUIRE(mf.pluralize(2, "apple", "apples") == "apples");
}

TEST_CASE("Gender handling") {
    MessageFormat2 mf("{gender}");
    REQUIRE(mf.genderize("He", "She", "They", "male") == "He");
    REQUIRE(mf.genderize("He", "She", "They", "female") == "She");
    REQUIRE(mf.genderize("He", "She", "They", "neutral") == "They");
}

TEST_CASE("Case transformation") {
    MessageFormat2 mf("{word}");
    REQUIRE(mf.transformCase("hello", "upper") == "HELLO");
    REQUIRE(mf.transformCase("WORLD", "lower") == "world");
}

