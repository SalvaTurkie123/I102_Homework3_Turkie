#include "ConstructorJson.h"

void ConstructorJson::imprimirInfo() const {
    std::cout << "{";
    for (size_t i = 0; i < info.size(); ++i) {
        if (i != 0) std::cout << " ";
        std::cout << " \"" << info[i].first << "\":" << info[i].second;
        if (i < info.size() - 1) {
            std::cout << ",";
        }
        std::cout << std::endl;
    }
    std::cout << "}" << std::endl;
}