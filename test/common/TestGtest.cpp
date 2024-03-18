#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <unordered_map>
#include <sstream>

using namespace testing;

// 自定义匹配器：将 std::unordered_map 转换为字符串
MATCHER_P(UnorderedMapMatches, expectedMap, "") {
    std::ostringstream os;
    os << "{";
    for (const auto& pair : arg) {
        os << pair.first << ":" << pair.second << ", ";
    }
    os << "}";
    return (os.str() == expectedMap);
}

TEST(UnorderedMapTest, CheckContents) {
    std::unordered_map<int, std::string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}};
    std::string expectedMapStr = "{1:one, 2:two, 3:three}";

    // 使用 EXPECT_THAT 结合自定义匹配器进行断言
    // EXPECT_THAT(myMap, UnorderedMapMatches(expectedMapStr));
}

class Calculator {
public:
    virtual int Add(int a, int b) const
    {
        return a + b;
    }
};

// MockCalculator 类，用于模拟 Calculator 类
class MockCalculator : public Calculator {
public:
    MOCK_CONST_METHOD2(Add, int(int a, int b));
};

// Test fixture，包含一个 MockCalculator 对象用于测试
class CalculatorTest : public Test {
protected:
    MockCalculator mockCalculator;
};

// 测试用例，测试 Add 方法
TEST_F(CalculatorTest, AddTest) {
    // 设置预期行为：给定两个参数时，返回它们的和为 5
    EXPECT_CALL(mockCalculator, Add(2, 3))
        .WillOnce(Return(5));

    // 调用被测函数
    int result = mockCalculator.Add(2, 3);

    // 验证结果
    ASSERT_EQ(result, 5);
}