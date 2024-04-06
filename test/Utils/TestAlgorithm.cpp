#include "Algorithm.h"
#include "gtest/gtest.h"

using namespace Utils;

class TestAlgorithm : public testing::Test
{
    void SetUp() {}

    void TearDown() {}
};

TEST_F(TestAlgorithm, TestAlgorithm)
{
    std::vector<int> v{3, 1, -14, 1, 5, 9};
    std::vector<int>::iterator result;

    result = std::max_element(v.begin(), v.end());
    std::cout << "max element:"
              << std::distance(v.begin(), result)
              << " value: " << *result << '\n';

    result = std::max_element(v.begin(), v.end(), [](int a, int b)
                              { return std::abs(a) < std::abs(b); });
    std::cout << "abs max element:"
              << std::distance(v.begin(), result)
              << " value: " << *result << '\n';
}