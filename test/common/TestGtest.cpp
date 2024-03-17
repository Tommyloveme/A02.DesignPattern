#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <unordered_map>
#include <sstream>

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