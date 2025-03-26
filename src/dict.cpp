#include "../include/dict.h"

const std::unordered_map<std::string, std::string> irregularPlurals = {
    {"mouse", "mice"},
    {"child", "children"},
    {"man", "men"},
    {"woman", "women"},
    {"tooth", "teeth"},
    {"foot", "feet"},
    {"goose", "geese"},
    {"person", "people"},
    {"ox", "oxen"}
};

const std::unordered_map<std::string, std::unordered_map<std::string, std::string>> caseForms = {
    {"apple", {{"nominative", "apple"}, {"accusative", "apple"}, {"genitive", "apple's"}}},
    {"cat", {{"nominative", "cat"}, {"accusative", "cat"}, {"genitive", "cat's"}}}
};

const std::unordered_map<std::string, std::string> adjectiveAgreement = {
    {"big", "big"},
    {"small", "small"},
    {"red", "red"},
    {"blue", "blue"},
    {"old", "old"},
    {"young", "young"}
};
