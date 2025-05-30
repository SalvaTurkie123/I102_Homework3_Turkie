#pragma once
#include <vector>
#include <sstream>
#include <iomanip>
#include <type_traits>

template<typename T>
std::string vectorToString(const std::vector<T>& vec) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if constexpr (std::is_floating_point_v<T>)
            oss << std::fixed << std::setprecision(1);
        oss << vec[i];
        if (i < vec.size() - 1)
            oss << ", ";
    }
    oss << "]";
    return oss.str();
}