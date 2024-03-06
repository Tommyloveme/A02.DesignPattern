#include <iostream>
#include <vector>
#include <type_traits>
#include <boost/lexical_cast.hpp>
#include "TestBoost.h"

using namespace std;
namespace testBoost {

// 示例枚举类型
enum class MyEnum {
    Value1,
    Value2,
    Value3
};

void SimplyTest()
{
    MyEnum e = MyEnum::Value2;

    int intVar = 123;
    short shortVar = 456;
    long longVar = 789;
    long long longLongVar = 1234567890;
    char charVar = 'A';
    unsigned int unsignedIntVar = 234;
    float floatVar = 3.14f;
    double doubleVar = 2.71828;
    long double longDoubleVar = 1.618033988749895;
    bool boolVar = true;

    // printf打印
    printf("==========\n");
    printf("%s\n", ToString(e).c_str());
    printf("%s\n", ToString(intVar).c_str());
    printf("%s\n", ToString(shortVar).c_str());
    printf("%s\n", ToString(longVar).c_str());
    printf("%s\n", ToString(longLongVar).c_str());
    printf("%s\n", ToString(charVar).c_str());
    printf("%s\n", ToString(unsignedIntVar).c_str());
    printf("%s\n", ToString(floatVar).c_str());
    printf("%s\n", ToString(doubleVar).c_str());
    printf("%s\n", ToString(longDoubleVar).c_str());
    printf("%s\n", ToString(boolVar).c_str());
}

void ContainerTest()
{
    bool boolean = true;
    std::vector<int> intVector = {1, 2, 3, 4, 5};
    std::vector<float> floatVector = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    std::vector<double> doubleVector = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<char> charVector = {'a', 'b', 'c', 'd', 'e'};
    std::vector<bool> boolVector = {true, false, true, false, true};
    std::vector<signed int> signedIntVector = {-1, -2, -3, -4, -5};
    std::vector<unsigned int> unsignedIntVector = {1, 2, 3, 4, 5};
    std::vector<short int> shortIntVector = {1, 2, 3, 4, 5};
    std::vector<long int> longIntVector = {1, 2, 3, 4, 5};
    std::vector<long long int> longLongIntVector = {1, 2, 3, 4, 5};
    std::vector<unsigned short int> unsignedShortIntVector = {1, 2, 3, 4, 5};
    std::vector<unsigned long int> unsignedLongIntVector = {1, 2, 3, 4, 5};
    std::vector<unsigned long long int> unsignedLongLongIntVector = {1, 2, 3, 4, 5};
    std::vector<std::string> stringVector = {"x", "y", "z"};
    std::set<double> doubleSet = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::map<std::string, int> doubleMap {{"apple", 5.1}, {"banana", 3.2}, {"orange", 8.3}};

    printf("%s\n", ToString(boolean).c_str());
    printf("%s\n", ToString(intVector).c_str());
    printf("%s\n", ToString(floatVector).c_str());
    printf("%s\n", ToString(doubleVector).c_str());
    printf("%s\n", ToString(charVector).c_str());
    printf("%s\n", ToString(boolVector).c_str());
    printf("%s\n", ToString(signedIntVector).c_str());
    printf("%s\n", ToString(unsignedIntVector).c_str());
    printf("%s\n", ToString(shortIntVector).c_str());
    printf("%s\n", ToString(longIntVector).c_str());
    printf("%s\n", ToString(longLongIntVector).c_str());
    printf("%s\n", ToString(unsignedShortIntVector).c_str());
    printf("%s\n", ToString(unsignedLongIntVector).c_str());
    printf("%s\n", ToString(unsignedLongLongIntVector).c_str());
    printf("stringVector = %s\n", ToString(stringVector).c_str());
    printf("doubleSet = %s\n", ToString(doubleSet).c_str());
    printf("doubleMap = %s\n", ToString(doubleMap).c_str());
}
} // namespace testBoost