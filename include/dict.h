#ifndef DICT_H
#define DICT_H

#include <unordered_map>
#include <string>

// Irregular plural forms
extern const std::unordered_map<std::string, std::string> irregularPlurals;

// Case mapping rules
extern const std::unordered_map<std::string, std::unordered_map<std::string, std::string>> caseForms;

// Adjective agreement rules
extern const std::unordered_map<std::string, std::string> adjectiveAgreement;

#endif
