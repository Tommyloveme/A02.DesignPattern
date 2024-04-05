#include <vector>
#include "gtest/gtest.h"

using namespace std;

class TestVariadicTemplate : public testing::Test
{
    void SetUp() {}

    void TearDown() {}
};

template <typename FirstType, typename... Args>
void Print(FirstType first, Args... args)
{
    std::cout << first;

    auto printWhiteSpace = [](const auto arg)
    { std::cout << " " << arg; };

    (..., printWhiteSpace(args));
}

TEST_F(TestVariadicTemplate, Test_Print)
{
    Print(123, "abc", true, 45.6);
}

template <typename... T>
auto FoldSum(T... s)
{
    return (... + s); // ((s1 + s2) + s3) ...
}

TEST_F(TestVariadicTemplate, Test_FoldSum)
{
    Print(123, "abc", true, 45.6);
}