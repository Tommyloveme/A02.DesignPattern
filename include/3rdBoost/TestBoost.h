#ifndef TEST_BOOST_HEADER
#define TEST_BOOST_HEADER

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <type_traits>
#include "MockBoostDescribeEnum.hpp"
#include "boost/lexical_cast.hpp"
#include <boost/describe.hpp>
#include <boost/mp11.hpp>

namespace testBoost
{
#define TOCHAR(T) ToString(T)

// 枚举类型转换为字符串的模板函数
template <typename E>
inline typename std::enable_if<std::is_enum<E>::value, std::string>::type ToString(const E& enumerator)
{
    std::string result = "[UNDEFINED]";
    boost::mp11::mp_for_each< boost::describe::describe_enumerators<E> >([&](auto description){
        if (enumerator == description.value) {
            result = description.name;
        }
    });
    return result + std::string("(") + std::to_string(static_cast<int>(enumerator)) + std::string(")");
}

// 基本类型转换为字符串的模板函数
template <typename T>
inline typename std::enable_if<!std::is_enum<T>::value && std::is_arithmetic<T>::value, std::string>::type ToString(T value)
{
    return boost::lexical_cast<std::string>(value);
}

template <typename T>
inline typename std::enable_if<!std::is_enum<T>::value && !std::is_arithmetic<T>::value, std::string>::type ToString(T value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

// boolean转换为字符串的模板函数
inline std::string ToString(bool boolean)
{
    return boolean ? "true" : "false";
}

// vector转换为字符串的模板函数
template <typename T>
inline std::string ToString(const std::vector<T>& vec)
{
    std::stringstream ss;
    ss << "[";
    if (!vec.empty())
    {
        // 输出第一个元素
        ss << ToString(vec[0]);
        // 输出剩余元素
        for (size_t i = 1; i < vec.size(); ++i)
        {
            ss << ", " << ToString(vec[i]);
        }
    }
    ss << "]";
    return ss.str();
}

// set转换为字符串的模板函数
template<typename T>
inline std::string ToString(const std::set<T>& container) {
    std::ostringstream oss;
    oss << "[";
    for (const auto& element : container) {
        oss << ToString(element) << ", ";
    }
    std::string result = oss.str();
    if (!result.empty()) {
        result.pop_back(); // 移除最后一个逗号
        result.pop_back(); // 移除空格
    }
    result += "]";
    return result;
}

// map转换为字符串的模板函数
template<typename KeyType, typename ValueType>
inline std::string ToString(const std::map<KeyType, ValueType>& inputMap) {
    std::ostringstream oss;
    oss << "{";
    for (const auto& pair : inputMap) {
        oss << "{"<< ToString(pair.first) << ": " << ToString(pair.second) << "}, ";
    }
    std::string result = oss.str();
    if (!result.empty()) {
        result.pop_back(); // 移除最后一个逗号
        result.pop_back(); // 移除空格
    }
    result += "}}";
    return result;
}

// unordered_map转换为字符串的模板函数
template<typename KeyType, typename ValueType>
inline std::string ToString(const std::unordered_map<KeyType, ValueType>& inputMap) {
    std::ostringstream oss;
    oss << "{";
    for (const auto& pair : inputMap) {
        oss << "{"<< ToString(pair.first) << ": " << ToString(pair.second) << "}, ";
    }
    std::string result = oss.str();
    if (!result.empty()) {
        result.pop_back(); // 移除最后一个逗号
        result.pop_back(); // 移除空格
    }
    result += "}}";
    return result;
}
} // testBoost

#endif // TEST_BOOST_HEADER