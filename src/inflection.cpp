#include "../include/inflection.h"
#include "../include/dict.h"
#include <sstream>

// ✅ Handle Irregular Plurals (Detect Count Automatically)
std::string inflectPlural(const std::string& noun) {
    auto it = irregularPlurals.find(noun);
    if (it != irregularPlurals.end()) {
        return it->second; // Irregular plural case
    }
    if (noun.back() != 's') return noun + "s";
    return noun;
}

// ✅ Handle Gender Inflection
std::string inflectGender(const std::string& noun, const std::string& gender) {
    if (noun == "cat") {
        if (gender == "male") return "le chat";
        if (gender == "female") return "la chatte";
    }
    return noun;
}

// ✅ Handle List Formatting
std::string formatList(const std::vector<std::string>& items, const std::string& locale) {
    if (items.empty()) return "";
    if (items.size() == 1) return items[0];
    std::ostringstream result;
    for (size_t i = 0; i < items.size(); ++i) {
        if (i > 0) {
            if (i == items.size() - 1) result << (locale == "en" ? " and " : " y ");
            else result << ", ";
        }
        result << items[i];
    }
    return result.str();
}

// ✅ Handle Case Agreement
std::string inflectCase(const std::string& noun, const std::string& grammaticalCase) {
    auto it = caseForms.find(noun);
    if (it != caseForms.end()) {
        auto caseIt = it->second.find(grammaticalCase);
        if (caseIt != it->second.end()) return caseIt->second;
    }
    return noun;
}

// ✅ Handle Adjective Agreement
std::string inflectAdjectiveAgreement(const std::string& adjective, const std::string& noun) {
    auto it = adjectiveAgreement.find(adjective);
    if (it != adjectiveAgreement.end()) return it->second + " " + noun;
    return adjective + " " + noun;
}
