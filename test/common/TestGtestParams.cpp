#include <gtest/gtest.h>
#include <tuple>
#include <vector>

struct MultiplyParams {
    int value1;
    int value2;
};

// 定义一个测试夹具
class MultiParameterizedTest : public testing::TestWithParam<MultiplyParams> {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

std::vector<MultiplyParams> test_data{
    MultiplyParams{1, 1},
    MultiplyParams{2, 4},
    MultiplyParams{3, 9},
    MultiplyParams{4, 16},
    MultiplyParams{5, 25},
};

// 使用TEST_P宏定义测试用例
TEST_P(MultiParameterizedTest, Multiply) {
    auto params = GetParam(); // 获取参数值
    int x = params.value1;
    int y = params.value2;
    int result = x * y;
    EXPECT_EQ(result, x * y);
}

// 使用test_data注册测试用例
INSTANTIATE_TEST_SUITE_P(MultiParamTest, MultiParameterizedTest, testing::ValuesIn(test_data));