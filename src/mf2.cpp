#include "../include/mf2.h"
#include "../include/inflection.h"
#include <sstream>

MessageFormat2::MessageFormat2(const std::string& templateStr) : templateStr(templateStr) {}

std::string MessageFormat2::format(const std::unordered_map<std::string, std::variant<
    int, std::string, std::vector<std::string>>>& args) {

    std::string result = templateStr;

    for (const auto& [key, value] : args) {
        std::string placeholder = "{" + key + "}";
        std::string replacement;

        if (std::holds_alternative<std::string>(value)) {
            replacement = inflectPlural(std::get<std::string>(value));
        }

        if (std::holds_alternative<std::vector<std::string>>(value)) {
            replacement = formatList(std::get<std::vector<std::string>>(value));
        }

        size_t pos = result.find(placeholder);
        if (pos != std::string::npos) {
            result.replace(pos, placeholder.length(), replacement);
        }
    }
    return result;
}
