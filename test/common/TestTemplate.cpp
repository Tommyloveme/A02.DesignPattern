#include "TestBoost.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <variant>
#include <type_traits>
#include <tuple>
#include <map>
#include <string>
#include "boost/variant.hpp"
#include "gtest/gtest.h"

using namespace testBoost;

class TestTemplate : public testing::Test
{
    void SetUp() {}

    void TearDown() {}
};


TEST_F(TestTemplate, base)
{
    // 定义一个映射，其值类型为 boost::variant，可以存储不同类型的值
    std::map<std::string, boost::variant<int, double, std::string>> myMap;

    // 向映射中插入键值对
    myMap["int_value"] = 42;
    myMap["double_value"] = 3.14;
    myMap["string_value"] = "hello";

    // 遍历映射并输出键值对
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": ";
        // 使用 boost::get 获取值，并根据值的类型进行输出
        if (auto intValue = boost::get<int>(&pair.second)) {
            std::cout << "int value: " << *intValue;
        } else if (auto doubleValue = boost::get<double>(&pair.second)) {
            std::cout << "double value: " << *doubleValue;
        } else if (auto stringValue = boost::get<std::string>(&pair.second)) {
            std::cout << "string value: " << *stringValue;
        }
        std::cout << std::endl;
    }
}