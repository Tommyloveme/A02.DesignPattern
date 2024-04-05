#ifndef NUMERICAL_JUDGMENT_HEADER
#define NUMERICAL_JUDGMENT_HEADER

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include "BaseType.h"
#include "VariableArgumentPerdicate.h"

namespace Utils {

template<typename... Args>
inline bool IsFinite(Args... args)
{
    return AllTrue(std::isfinite(args)...);
}

inline bool IsFinite(const xy_vect& xy)
{
    return AllTrue(IsFinite(xy.x), IsFinite(xy.y));
}

template<typename T>
inline bool IsFinite(const std::vector<T>& container)
{
    return std::all_of(container.begin(), container.end(), [](const auto& elem) { return IsFinite(elem); });
}

template<typename T>
inline bool IsFinite(const std::list<T>& container)
{
    return std::all_of(container.begin(), container.end(), [](const auto& elem) { return IsFinite(elem); });
}

template<typename keyType, typename valueType>
inline bool IsFinite(const std::map<keyType, valueType>& container)
{
    return std::all_of(container.begin(), container.end(), [](const auto& elem) { return IsFinite(elem.second); });
}

template<typename keyType, typename valueType>
inline bool IsFinite(const std::unordered_map<keyType, valueType>& container)
{
    return std::all_of(container.begin(), container.end(), [](const auto& elem) { return IsFinite(elem.second); });
}

} // namespace Utils

#endif // NUMERICAL_JUDGMENT_HEADER