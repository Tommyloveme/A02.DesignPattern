#include "gtest/gtest.h"
#include "NumericalJudgement.h"
#include <vector>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>

using namespace std;
using namespace Utils;

// 定义一个仿函数，用于检查元素是否满足特定条件
template <typename T>
class MyPredicate {
public:
    MyPredicate(const T& target) : m_target(target) {}

    // 重载()运算符，使对象像函数一样被调用
    bool operator()(const T& element) const {
        return element > m_target; // 这里可以根据需要修改条件
    }

private:
    T m_target;
};

// 自定义的 find_if 函数，接受容器、条件对象，并返回满足条件的元素集合
template <typename Container, typename Predicate>
std::vector<typename Container::value_type> find_if_custom(const Container& container, Predicate pred) {
    std::vector<typename Container::value_type> result;
    for (const auto& element : container) {
        if (pred(element)) {
            result.push_back(element);
        }
    }
    return result;
}

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

TEST_F(TestPredicate, test_for_find_if)
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<double> lst = {3.14, 2.71, 1.618, 2.718, 3.142};

    // 使用自定义的 find_if_custom 函数查找满足条件的元素
    int target_int = 3;
    auto int_result = find_if_custom(vec, MyPredicate<int>(target_int));
    std::cout << "Integers matching the predicate: ";
    for (auto& element : int_result) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    double target_double = 3.14;
    auto double_result = find_if_custom(lst, MyPredicate<double>(target_double));
    std::cout << "Doubles matching the predicate: ";
    for (auto& element : double_result) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

TEST_F(TestPredicate, test_for_is_finite)
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