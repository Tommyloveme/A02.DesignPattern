#include <iostream>
#include "DesignPattern.h"
#include "gtest/gtest.h"

using namespace std;
using namespace DP;

class TestSolution : public testing::Test
{
    void SetUp() {
        m_solution = std::make_shared<DesignPattern>();
    }

    void TearDown() {}

protected:
    std::shared_ptr<DesignPattern> m_solution;
};

TEST_F(TestSolution, test)
{
    
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}