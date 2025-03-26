#ifndef DICT_H
#define DICT_H

#include <unordered_map>
#include <string>
#include <utility>

// Irregular plural forms mapping
extern const std::unordered_map<std::string, std::string> irregularPlurals;

// Case-based inflection mapping
extern const std::unordered_map<std::string, std::unordered_map<std::string, std::string>> caseForms;

// Adjective agreement mapping
extern const std::unordered_map<std::string, std::string> adjectiveAgreement;

// Gender-based mapping (male, female forms)
extern const std::unordered_map<std::string, std::pair<std::string, std::string>> genderMap;

#endif

