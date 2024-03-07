// #ifndef TEST_BOOST_HEADER
// #define TEST_BOOST_HEADER

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <type_traits>
#include <boost/lexical_cast.hpp>

namespace testBoost
{
    // 枚举类型转换为字符串的模板函数
    template <typename T>
    inline typename std::enable_if<std::is_enum<T>::value, std::string>::type
    ToString(const T& value)
    {
        return std::to_string(static_cast<typename std::underlying_type<T>::type>(value));
    }

    // 基本类型转换为字符串的模板函数
    template <typename T>
    inline typename std::enable_if<!std::is_enum<T>::value, std::string>::type
    ToString(T value)
    {
        return boost::lexical_cast<std::string>(value);
    }

    // boolean转换为字符串的模板函数
    inline std::string ToString(bool boolean)
    {
        return boolean ? "true" : "false";
    }

    // vector转换为字符串的模板函数
    template <typename T>
    inline std::string ToString(std::vector<T> &vec)
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

    // void SimplyTest();
    // void ContainerTest();
} // testBoost

// #endif // TEST_BOOST_HEADER