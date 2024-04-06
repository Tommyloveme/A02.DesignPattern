#ifndef VARIABLE_ARGUMENT_PREDICATE_H
#define VARIABLE_ARGUMENT_PREDICATE_H

#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>

namespace Utils
{

template<typename... Args>
inline bool AllTrue(Args... args)
{
    return (... && args);
}

template<typename... Args>
inline bool AllFalse(Args... args)
{
    return !(... || args);
}

template<typename T>
inline bool AllTrue(std::vector<T> container)
{
    return all_of(container.begin(), container.end(), [](const T& elem){return AllTrue(elem);});
}

template<typename T>
inline bool AllTrue(std::list<T> container)
{
    return all_of(container.begin(), container.end(), [](const T& elem){return AllTrue(elem);});
}

template<typename T>
inline bool AllTrue(std::set<T> container)
{
    return all_of(container.begin(), container.end(), [](const T& elem){return AllTrue(elem);});
}

template<typename KeyType, typename ValueType>
inline bool AllTrue(std::map<KeyType, ValueType> container)
{
    return all_of(container.begin(), container.end(), [](const auto& elem){return AllTrue(elem.second);});
}

template<typename KeyType, typename ValueType>
inline bool AllTrue(std::unordered_map<KeyType, ValueType> container)
{
    return all_of(container.begin(), container.end(), [](const auto& elem){return AllTrue(elem.second);});
}

template<typename T>
inline bool AllFalse(std::vector<T> container)
{
    return all_of(container.begin(), container.end(), [](const T& elem){return AllFalse(elem);});
}

template<typename T>
inline bool AllFalse(std::list<T> container)
{
    return all_of(container.begin(), container.end(), [](const T& elem){return AllFalse(elem);});
}

template<typename T>
inline bool AllFalse(std::set<T> container)
{
    return all_of(container.begin(), container.end(), [](const T& elem){return AllFalse(elem);});
}

template<typename KeyType, typename ValueType>
inline bool AllFalse(std::map<KeyType, ValueType> container)
{
    return all_of(container.begin(), container.end(), [](const auto& elem){return AllFalse(elem.second);});
}

template<typename KeyType, typename ValueType>
inline bool AllFalse(std::unordered_map<KeyType, ValueType> container)
{
    return all_of(container.begin(), container.end(), [](const auto& elem){return AllFalse(elem.second);});
}

} // namespace Utils
#endif // VARIABLE_ARGUMENT_PREDICATE_H