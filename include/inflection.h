#ifndef INFLECTION_H
#define INFLECTION_H

#include <string>
#include <vector>

// Updated to take only string (automatic inference)
std::string inflectPlural(const std::string& noun);
std::string inflectGender(const std::string& noun, const std::string& gender);
std::string formatList(const std::vector<std::string>& items, const std::string& locale = "en");
std::string inflectCase(const std::string& noun, const std::string& grammaticalCase);
std::string inflectAdjectiveAgreement(const std::string& adjective, const std::string& noun);

#endif
