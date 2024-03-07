#include <iostream>
#include "gtest/gtest.h"
#include <boost/lexical_cast.hpp>
#include <string>

using namespace std;

// 枚举类型定义
enum class Enum1 {
    Value1,
    Value2,
    Value3
};

// ToString模板函数
template<typename T>
typename std::enable_if<std::is_enum<T>::value, std::string>::type
ToString(const T& enumValue)
{
    return "";
}

template <typename T>
typename std::enable_if<!std::is_enum<T>::value, std::string>::type
ToString(T value)
{
    return boost::lexical_cast<std::string>(value);
}

inline std::string ToString(bool boolean)
{
    return boolean ? "true" : "false";
}

template <typename T>
std::string ToString(std::vector<T> &vec)
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

// 特例化模板函数为testBoost::Enum1类型
template<>
std::string ToString<Enum1>(const Enum1& enumValue) {
    switch (enumValue) {
        case Enum1::Value1:
            return "Custom String for Value1";
        case Enum1::Value2:
            return "Custom String for Value2";
        case Enum1::Value3:
            return "Custom String for Value3";
        default:
            return "Unknown Enum Value";
    }
}

class TestBoost : public testing::Test
{
    void SetUp()
    {}

    void TearDown()
    {}
};

TEST_F(TestBoost, test)
{
    cout << ToString(Enum1::Value1) << endl;
}