#define CATCH_CONFIG_RUNNER
#include "../include/catch.hpp"
#include "../include/inflection.h"
#include "../include/dict.h"

TEST_CASE("Inflecting Plurals", "[plural]") {
    // Regular plural forms
    REQUIRE(inflectPlural("2 cat") == "2 cats");
    REQUIRE(inflectPlural("3 apple") == "3 apples");
    REQUIRE(inflectPlural("5 car") == "5 cars");

    // Irregular plural forms
    REQUIRE(inflectPlural("2 mouse") == "2 mice");
    REQUIRE(inflectPlural("3 child") == "3 children");
    REQUIRE(inflectPlural("2 person") == "2 people");
    REQUIRE(inflectPlural("4 tooth") == "4 teeth");
    REQUIRE(inflectPlural("3 foot") == "3 feet");

    // Edge cases
    REQUIRE(inflectPlural("1 sheep") == "1 sheep"); // No plural change
    REQUIRE(inflectPlural("2 fish") == "2 fish");   // No plural change
}

TEST_CASE("Inflecting Gender", "[gender]") {
    REQUIRE(inflectGender("cat", "male") == "le chat");
    REQUIRE(inflectGender("cat", "female") == "la chatte");
}

TEST_CASE("Case Agreement", "[case]") {
    REQUIRE(inflectCase("apple", "genitive") == "apple's");
    REQUIRE(inflectCase("cat", "nominative") == "cat");
}

TEST_CASE("Adjective Agreement", "[adjective]") {
    REQUIRE(inflectAdjectiveAgreement("big", "apple") == "big apple");
    REQUIRE(inflectAdjectiveAgreement("red", "car") == "red car");
}

TEST_CASE("List Formatting", "[list]") {
    std::vector<std::string> list1 = {"apple", "banana", "orange"};
    REQUIRE(formatList(list1) == "apple, banana and orange");

    std::vector<std::string> list2 = {"manzana", "plátano", "naranja"};
    REQUIRE(formatList(list2, "es") == "manzana, plátano y naranja");
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}

