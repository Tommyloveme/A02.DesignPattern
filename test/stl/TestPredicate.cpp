#include <vector>
#include "gtest/gtest.h"

using namespace std;

class TestPredicate : public testing::Test
{
    void SetUp() {}

    void TearDown() {}
};

TEST_F(TestPredicate, test_for_transform_common)
{
    std::vector<int> container = {1, 2, 3, 4, 5};
    std::vector<int> destination = {};
    std::transform(container.begin(), container.end(), container.begin(), [](const auto &elem)
                   { return elem * 2; });
    std::vector<int> target = {2, 4, 6, 8, 10};
    EXPECT_EQ(container, target);
}