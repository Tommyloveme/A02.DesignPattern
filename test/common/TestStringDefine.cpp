#include <gtest/gtest.h>
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <cstdarg>
#include <cmath>
#include <sstream>
#include "TestBoost.h"

using namespace std;


// #define DEFINE_TOSTRING_FOR_STRUCT(StructName, ...) \
//     std::string ToString(const StructName& self) { \
//         std::stringstream os; \
//         os << #StructName << " { "; \
//         ToStringMembers(os, self, #__VA_ARGS__); \
//         os << " }" << std::endl; \
//         return os.str(); \
//     }

// #define DEFINE_TOSTRING_MEMBERS(os, name, member) \
//     os << name << " = " << member << ", "

// #define TO_STRING_MEMBER(obj, name) obj.name

// #define TOSTRING_FOR_MEMBER(obj, name) TO_STRING_MEMBER(obj, name)

// #define ToStringMembers(os, self, ...) \
//     do { \
//         int dummy[] = {0, (DEFINE_TOSTRING_MEMBERS(os, __VA_ARGS__, TOSTRING_FOR_MEMBER(self, __VA_ARGS__)), 0)...}; \
//         (void)dummy; \
//     } while (0)

// // 定义一个结构体
// struct Person {
//     std::string name;
//     int age;
// };

// // 使用宏定义 ToString 方法
// DEFINE_TOSTRING_FOR_STRUCT(Person, name, age)

TEST(TestStringDefine, basic)
{
    // Person person{"Alice", 30};
    // std::cout << ToString(person) << std::endl;
}