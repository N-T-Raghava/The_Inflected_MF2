#ifndef MF2_H
#define MF2_H

#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

class MessageFormat2 {
public:
    explicit MessageFormat2(const std::string &pattern);
    std::string format(const std::unordered_map<std::string, std::variant<int, std::string, std::vector<std::string>>> &args);

public:
    std::string pattern;

    std::string handleArgument(const std::string &key, const std::variant<int, std::string, std::vector<std::string>> &value);
    std::string formatList(const std::vector<std::string> &items);

    // Direct grammar handling
    std::string pluralize(int count, const std::string &singular, const std::string &plural);
    std::string genderize(const std::string &male, const std::string &female, const std::string &neutral, const std::string &gender);
    std::string transformCase(const std::string &input, const std::string &caseType);
};

#endif

