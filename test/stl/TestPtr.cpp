#include "gtest/gtest.h"
#include <memory>

using namespace std;

class TestAlgorithmStl : public testing::Test
{
    void SetUp() {}

    void TearDown() {}
};

class TestPtr {
public:
    TestPtr() : m_int(std::make_unique<int>(10)) {}w

    std::unique_ptr<int> m_int;
};

TEST_F(TestAlgorithmStl, test_for_max_min_element)
{
    TestPtr test;
    TestPtr test2 = test;
}