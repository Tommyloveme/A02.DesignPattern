#include "gtest/gtest.h"
#include "VariableArgumentPerdicate.h"

using namespace std;
using namespace Utils;

class TestVariableArgumentPerdicate : public testing::Test
{
    void SetUp() {}

    void TearDown() {}
};

TEST_F(TestVariableArgumentPerdicate, test_for_all_true)
{
    bool a = true;
    bool b = true;
    bool c = false;
    bool d = false;

    EXPECT_EQ(AllTrue(a), true);
    EXPECT_EQ(AllTrue(a, b), true);
    EXPECT_EQ(AllTrue(a, b, c), false);
    EXPECT_EQ(AllFalse(a), false);
    EXPECT_EQ(AllFalse(a, b), false);
    EXPECT_EQ(AllFalse(c, d), true);

    std::vector<bool> v = {a, b};
    EXPECT_EQ(AllTrue(v), true);
    v = {c, d};
    EXPECT_EQ(AllFalse(v), true);

    std::list<bool> listBool = {a, b};
    EXPECT_EQ(AllTrue(listBool), true);
    listBool = {c, d};
    EXPECT_EQ(AllFalse(listBool), true);

    std::set<bool> setBool = {a, b};
    EXPECT_EQ(AllTrue(setBool), true);
    setBool = {c, d};
    EXPECT_EQ(AllFalse(setBool), true);

    std::map<int, bool> mapBool = {{1, a}, {2, b}};
    EXPECT_EQ(AllTrue(mapBool), true);
    mapBool = {{1, c}, {2, d}};
    EXPECT_EQ(AllFalse(mapBool), true);

    std::unordered_map<int, bool> umapBool = {{1, a}, {2, b}};
    EXPECT_EQ(AllTrue(umapBool), true);
    umapBool = {{1, c}, {2, d}};
    EXPECT_EQ(AllFalse(umapBool), true);
}