#include <cmath>
#include "gtest/gtest.h"
#include "NumericalJudgement.h"
#include "VariableArgumentPerdicate.h"
#include "Basetype.h"

using namespace std;
using namespace Utils;

class TestVariableArgumentPerdicate : public testing::Test
{
    void SetUp() {}

    void TearDown() {}
};

TEST_F(TestVariableArgumentPerdicate, test_for_allTrue_allFalse)
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

TEST_F(TestVariableArgumentPerdicate, test_for_isOneOf)
{
    EXPECT_EQ(IsOneOf(1, 1, 2, 3), true);
    CHUCK_ID chuck = CHUCK_1;
    EXPECT_EQ(IsOneOf(chuck, CHUCK_1, CHUCK_2), true);
    EXPECT_EQ(IsOneOf(chuck, CHUCK_2, CHUCK_MAX), false);

    EXPECT_EQ(IsOneOf(1, {1, 2, 3}), true);
    EXPECT_EQ(IsOneOf(chuck, {CHUCK_1, CHUCK_2}), true);
    EXPECT_EQ(IsOneOf(chuck, {CHUCK_2, CHUCK_MAX}), false);
}

TEST_F(TestVariableArgumentPerdicate, test_for_is_finite)
{
    double validValue = 3.14;
    EXPECT_EQ(IsFinite(validValue), true);
    double nan = NAN;
    EXPECT_EQ(IsFinite(nan), false);
    EXPECT_EQ(IsFinite(validValue, nan), false);

    xy_vect pos {1.0, 2.0};
    EXPECT_EQ(IsFinite(pos), true);

    xy_vect nan_pos {NAN, NAN};
    EXPECT_EQ(IsFinite(nan_pos), false);

    std::vector<double> vec = {1.0, 2.0, 3.0, 4.0, 5.0};
    EXPECT_EQ(IsFinite(vec), true);

    std::vector<double> vec_nan = {1.0, 2.0, NAN, 4.0, 5.0};
    EXPECT_EQ(IsFinite(vec_nan), false);

    std::list<double> lst = {1.0, 2.0, 3.0, 4.0, 5.0};
    EXPECT_EQ(IsFinite(lst), true);

    std::list<double> lst_nan = {1.0, 2.0, NAN, 4.0, 5.0};
    EXPECT_EQ(IsFinite(lst_nan), false);

    std::map<int, double> mapper = {{1, 1.0}, {2, 2.0}, {3, 3.0}, {4, 4.0}, {5, 5.0}};
    EXPECT_EQ(IsFinite(mapper), true);

    std::map<int, double> mapper_nan = {{1, 1.0}, {2, 2.0}, {3, NAN}, {4, 4.0}, {5, 5.0}};
    EXPECT_EQ(IsFinite(mapper_nan), false);

    std::unordered_map<int, double> umapper = {{1, 1.0}, {2, 2.0}, {3, 3.0}, {4, 4.0}, {5, 5.0}};
    EXPECT_EQ(IsFinite(umapper), true);

    std::unordered_map<int, double> umapper_nan = {{1, 1.0}, {2, 2.0}, {3, NAN}, {4, 4.0}, {5, 5.0}};
    EXPECT_EQ(IsFinite(umapper_nan), false);
}