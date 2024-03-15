#include "TestBoost.h"
#include "TestJson.h"
#include <iostream>
#include <string>
#include <set>
#include "gtest/gtest.h"
#include "boost/lexical_cast.hpp"
#include "boost/describe.hpp"
#include "boost/mp11.hpp"

using namespace std;
using namespace testBoost;
using namespace testJson;
using json = nlohmann::json;

#define LOG_I(fmt, msg...) printf("[INFO] "#fmt, ##msg)

enum class Value {
    Value1 = 1,
    Value2,
    Value3
};
BOOST_DESCRIBE_ENUM(Value, Value1)

enum MyEnum {
    Item1 = 1,
    Item2,
    Item3,
    Item4,
    Item5,
    Item6,
    Item7,
    Item8,
    Item9,
    Item10,
    Item11,
    Item12,
    Item13,
    Item14,
    Item15,
    Item16,
    Item17,
    Item18,
    Item19,
    Item20,
    Item21,
    Item22,
    Item23,
    Item24,
    Item25,
    Item26,
    Item27,
    Item28,
    Item29,
    Item30,
    Item31,
    Item32,
    Item33,
    Item34,
    Item35,
    Item36,
    Item37,
    Item38,
    Item39,
    Item40,
    Item41,
    Item42,
    Item43,
    Item44,
    Item45,
    Item46,
    Item47,
    Item48,
    Item49,
    Item50,
    Item51,
    Item52,
    Item53,
    Item54,
    Item55,
    Item56,
    Item57,
    Item58,
    Item59,
    Item60,
    Item61,
    Item62,
    Item63,
    Item64,
    Item65,
    Item66,
    Item67,
    Item68,
    Item69,
    Item70,
    Item71,
    Item72,
    Item73,
    Item74,
    Item75,
    Item76,
    Item77,
    Item78,
    Item79,
    Item80,
    Item81,
    Item82,
    Item83,
    Item84,
    Item85,
    Item86,
    Item87,
    Item88,
    Item89,
    Item90,
    Item91,
    Item92,
    Item93,
    Item94,
    Item95,
    Item96,
    Item97,
    Item98,
    Item99,
    Item100,
    Item101,
    Item102,
    Item103,
    Item104,
    Item105,
    Item106,
    Item107,
    Item108,
    Item109,
    Item110,
    Item111,
    Item112,
    Item113,
    Item114,
    Item115,
    Item116,
    Item117,
    Item118,
    Item119,
    Item120,
    Item121,
    Item122,
    Item123,
    Item124,
    Item125,
    Item126,
    Item127,
    Item128,
    Item129,
    Item130,
    Item131,
    Item132,
    Item133,
    Item134,
    Item135,
    Item136,
    Item137,
    Item138,
    Item139,
    Item140,
    Item141,
    Item142,
    Item143,
    Item144,
    Item145,
    Item146,
    Item147,
    Item148,
    Item149,
    Item150
};

BOOST_DESCRIBE_ENUM(MyEnum, Item1, Item2, Item3, Item4, Item5, Item6, Item7, Item8, Item9, Item10, Item11, Item12, Item13, Item14, Item15, Item16, Item17, Item18, Item19, Item20, Item21, Item22, Item23, Item24, Item25, Item26, Item27, Item28, Item29, Item30, Item31, Item32, Item33, Item34, Item35, Item36, Item37, Item38, Item39, Item40, Item41, Item42, Item43, Item44, Item45, Item46, Item47, Item48, Item49, Item50, Item51, Item52, Item53, Item54, Item55, Item56, Item57, Item58, Item59, Item60, Item61, Item62, Item63, Item64, Item65, Item66, Item67, Item68, Item69, Item70, Item71, Item72, Item73, Item74, Item75, Item76, Item77, Item78, Item79, Item80, Item81, Item82, Item83, Item84, Item85, Item86, Item87, Item88, Item89, Item90, Item91, Item92, Item93, Item94, Item95, Item96, Item97, Item98, Item99, Item100, Item101, Item102, Item103, Item104, Item105, Item106, Item107, Item108, Item109, Item110, Item111, Item112, Item113, Item114, Item115, Item116, Item117, Item118, Item119, Item120, Item121, Item122, Item123, Item124, Item125, Item126, Item127, Item128, Item129, Item130, Item131, Item132, Item133, Item134, Item135, Item136, Item137, Item138, Item139, Item140, Item141, Item142, Item143, Item144, Item145, Item146, Item147, Item148, Item149, Item150)

class TestBoost : public testing::Test
{
    void SetUp()
    {}

    void TearDown()
    {}
};

TEST_F(TestBoost, ToString_for_basic_type)
{
    MyEnum e = MyEnum::Item150;
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

    cout << ToString(e) << endl;
    EXPECT_EQ(ToString(e), "Item150(150)");
    EXPECT_EQ(ToString(intVar), "123");
    EXPECT_EQ(ToString(shortVar), "456");
    EXPECT_EQ(ToString(longVar), "789");
    EXPECT_EQ(ToString(longLongVar), "1234567890");
    EXPECT_EQ(ToString(charVar), "A");
    EXPECT_EQ(ToString(unsignedIntVar), "234");
    EXPECT_EQ(ToString(floatVar), "3.1400001");
    EXPECT_EQ(ToString(doubleVar), "2.71828");
    EXPECT_EQ(ToString(longDoubleVar), "1.6180339887498949");
    EXPECT_EQ(ToString(boolVar), "true");
}

TEST_F(TestBoost, ToString_for_container_type)
{
    std::vector<std::string> stringVector = {"x", "y", "z"};
    std::set<double> doubleSet = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::map<std::string, int> doubleMap {{"apple", 5.1}, {"banana", 3.2}, {"orange", 8.3}};
    std::unordered_map<std::string, int> doubleUnorderedMap {{"apple", 5.1}, {"banana", 3.2}, {"orange", 8.3}};
    std::unordered_map<std::string, std::vector<int>> nestedUnorderedMap {{"a", {1, 2}}, {"b", {3}}, {"c", {4, 5, 6}}};

    EXPECT_EQ(ToString(stringVector), "[x, y, z]");
    EXPECT_EQ(ToString(doubleSet), "[1.1000000000000001, 2.2000000000000002, 3.2999999999999998, 4.4000000000000004, 5.5]");
    EXPECT_EQ(ToString(doubleMap), "{{apple: 5}, {banana: 3}, {orange: 8}}}");
    EXPECT_EQ(ToString(doubleUnorderedMap), "{{orange: 8}, {banana: 3}, {apple: 5}}}");
    EXPECT_EQ(ToString(nestedUnorderedMap), "{{c: [4, 5, 6]}, {b: [3]}, {a: [1, 2]}}}");
}

struct Worker {
    std::string name;
    int age;
    MyEnum e;

    friend std::ostream& operator<<(std::ostream& os, const Worker& self) // #TODO: 思考enum的流式化序列化方案
    {
        os << "name = " << self.name << "; age = " << self.age << "; e = " << ToString(self.e) << std::endl;
        return os;
    }
};

TEST_F(TestBoost, ToString_for_custom_structure)
{
    EXPECT_EQ(ToString(Worker {"Jack", 27, Item150}), "name = Jack; age = 27; e = Item150(150)\n");
}

// 定义一个示例的模型类
class Person {
public:
    std::string name;
    int age;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Person, name, age)
    friend std::ostream& operator<<(std::ostream& os, const Person& self)
    {
        os << json(self).dump();
        return os;
    }
};

int TestJsonSet() {
    // 创建一个 std::set 对象
    std::set<int> mySet = {1, 2, 3, 4, 5};

    // 将 std::set 对象转换为 JSON 数组
    nlohmann::json jsonArray;
    for (const auto& elem : mySet) {
        jsonArray.push_back(elem);
    }

    // 打印生成的 JSON 字符串
    std::cout << jsonArray.dump() << std::endl;

    return 0;
}

TEST_F(TestBoost, ToString_for_json)
{
    // 创建一个 Person 对象
    Person person;
    person.name = "Alice";
    person.age = 30;

    TestJsonSet();
    EXPECT_EQ(ToString(person), R"({"age":30,"name":"Alice"})");
}