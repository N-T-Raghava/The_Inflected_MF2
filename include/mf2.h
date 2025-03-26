#ifndef MF2_H
#define MF2_H

#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

class MessageFormat2 {
public:
    MessageFormat2(const std::string& templateStr);
    std::string format(const std::unordered_map<std::string, std::variant<
        int, 
        std::string, 
        std::vector<std::string>>>& args);

private:
    std::string templateStr;
};

#endif
