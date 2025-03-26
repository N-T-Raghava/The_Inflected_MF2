#include "../include/mf2.h"
#include "../include/inflection.h"
#include <iostream>

int main() {
    MessageFormat2 mf("{object}");
    std::cout << mf.format({{"object", inflectPlural("mouse")}}) << std::endl;
    std::cout << mf.format({{"object", inflectPlural("child")}}) << std::endl;

    return 0;
}
