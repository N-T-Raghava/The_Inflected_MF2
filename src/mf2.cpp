#include "mf2.h"
#include <sstream>
#include <algorithm>
#include <stdexcept>

MessageFormat2::MessageFormat2(const std::string &pattern) : pattern(pattern) {}

std::string MessageFormat2::format(const std::unordered_map<std::string, std::variant<int, std::string, std::vector<std::string>>> &args) {
    std::ostringstream result;
    size_t i = 0;

    while (i < pattern.size()) {
        if (pattern[i] == '{') {
            size_t end = pattern.find('}', i);
            if (end == std::string::npos) throw std::runtime_error("Unmatched { in pattern");

            std::string key = pattern.substr(i + 1, end - i - 1);
            if (args.find(key) != args.end()) {
                result << handleArgument(key, args.at(key));
            } else {
                throw std::runtime_error("Missing argument: " + key);
            }
            i = end + 1;
        } else {
            result << pattern[i];
            i++;
        }
    }

    return result.str();
}

std::string MessageFormat2::handleArgument(const std::string &key, const std::variant<int, std::string, std::vector<std::string>> &value) {
    if (std::holds_alternative<int>(value)) {
        return std::to_string(std::get<int>(value));
    } else if (std::holds_alternative<std::string>(value)) {
        return std::get<std::string>(value);
    } else if (std::holds_alternative<std::vector<std::string>>(value)) {
        return formatList(std::get<std::vector<std::string>>(value));
    }
    throw std::runtime_error("Unsupported type for key: " + key);
}

std::string MessageFormat2::formatList(const std::vector<std::string> &items) {
    size_t size = items.size();
    if (size == 0) return "";
    if (size == 1) return items[0];
    if (size == 2) return items[0] + " and " + items[1];
    
    std::ostringstream result;
    for (size_t i = 0; i < size; i++) {
        result << items[i];
        if (i < size - 2) {
            result << ", ";
        } else if (i == size - 2) {
            result << ", and ";
        }
    }
    return result.str();
}

// Direct handling of pluralization
std::string MessageFormat2::pluralize(int count, const std::string &singular, const std::string &plural) {
    return (count == 1) ? singular : plural;
}

// Direct handling of gender inflection
std::string MessageFormat2::genderize(const std::string &male, const std::string &female, const std::string &neutral, const std::string &gender) {
    if (gender == "male") return male;
    if (gender == "female") return female;
    return neutral;
}

// Direct handling of case transformation
std::string MessageFormat2::transformCase(const std::string &input, const std::string &caseType) {
    std::string result = input;
    if (caseType == "upper") {
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    } else if (caseType == "lower") {
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    }
    return result;
}

