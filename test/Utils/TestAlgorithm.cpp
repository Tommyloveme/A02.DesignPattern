#include <iostream>
#include <limits>
#include "Algorithm.h"
#include "TestBoost.h"
#include "gtest/gtest.h"

using namespace std;
using namespace Utils;

constexpr double ESTIMATED_ERROR = 1e-14;

struct Pos {
    double x;
    double y;
};

class TestAlgorithm : public testing::Test
{
protected:
    void SetUp() override
    {
        m_intVec = {1, 2, 3, 4, 5};
        m_doubleVec = {1.0, 2.0, 3.0, 4.0, 5.0};
        m_doubleVecWithNan = {1.0, 2.0, NAN, 4.0, 5.0};
        m_posVecWithNan = {{1.0, 2.0}, {NAN, 2.0}, {1.0, NAN}, {NAN, NAN}};
    }

    void TearDown() override
    {}

    std::vector<int> m_intVec;
    std::vector<double> m_doubleVec;
    std::vector<double> m_doubleVecWithNan;
    std::vector<Pos> m_posVecWithNan;
};

TEST_F(TestAlgorithm, ElementSumTest)
{
    EXPECT_TRUE(isfinite(ElementSum(std::vector<int>{})));
    EXPECT_TRUE(isfinite(ElementSum(std::vector<double>{})));
    EXPECT_EQ(ElementSum(m_intVec), 15);
    EXPECT_NEAR(ElementSum(m_doubleVec), 15, ESTIMATED_ERROR);
    EXPECT_NEAR(ElementSum<double>(m_doubleVecWithNan, [](double elem)
                                   { return isfinite(elem) ? elem : 0.0; }),
                12, ESTIMATED_ERROR);
    EXPECT_NEAR(ElementSum<double>(m_posVecWithNan, [](const Pos &pos)
                                   { return isfinite(pos.x) ? pos.x : 0.0; }),
                2.0, ESTIMATED_ERROR);
    EXPECT_NEAR(ElementSum<double>(m_posVecWithNan, [](const Pos &pos)
                                   { return isfinite(pos.y) ? pos.y : 0.0; }),
                4.0, ESTIMATED_ERROR);
}

TEST_F(TestAlgorithm, ElementAveTest)
{
    EXPECT_FALSE(isfinite(ElementAve(std::vector<int>{})));
    EXPECT_FALSE(isfinite(ElementAve(std::vector<double>{})));
    EXPECT_EQ(ElementAve(m_intVec), 3);
    EXPECT_NEAR(ElementAve(m_doubleVec), 3.0, 0.00001);
    EXPECT_NEAR(ElementAve(m_doubleVecWithNan, [](double elem)
                           { return isfinite(elem); }),
                3, ESTIMATED_ERROR);
}

TEST_F(TestAlgorithm, ElementMaxTest)
{
    EXPECT_NEAR(ElementMax(std::vector<int>{}), std::numeric_limits<int>::max(), ESTIMATED_ERROR);
    EXPECT_NEAR(ElementMax(std::vector<double>{}), std::numeric_limits<double>::max(), ESTIMATED_ERROR);
    EXPECT_EQ(ElementMax(m_intVec), 5);
    EXPECT_EQ(ElementMax(m_doubleVec), 5);
}

TEST_F(TestAlgorithm, ElementMinTest)
{
    EXPECT_NEAR(ElementMin(std::vector<int>{}), std::numeric_limits<int>::max(), ESTIMATED_ERROR);
    EXPECT_NEAR(ElementMin(std::vector<double>{}), std::numeric_limits<double>::max(), ESTIMATED_ERROR);
    EXPECT_EQ(ElementMin(m_intVec), 1);
    EXPECT_EQ(ElementMin(m_doubleVec), 1);
}