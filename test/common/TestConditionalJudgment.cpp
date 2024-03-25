#include "ConditionalJudgment.h"
#include "gtest/gtest.h"

using namespace Judgment;

class TestConditionalJudgment : public testing::Test
{
    void SetUp() {}

    void TearDown() {}
};

TEST_F(TestConditionalJudgment, basement)
{
    EXPECT_TRUE(AllTrue(true, true));
}