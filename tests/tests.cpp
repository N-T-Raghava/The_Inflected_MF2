#define CATCH_CONFIG_RUNNER
#include "../include/catch.hpp"
#include "../include/inflection.h"
#include "../include/dict.h"

TEST_CASE("Inflecting Plurals", "[plural]") {
    REQUIRE(inflectPlural("mouse") == "mice");
    REQUIRE(inflectPlural("child") == "children");
    REQUIRE(inflectPlural("cat") == "cats");
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

