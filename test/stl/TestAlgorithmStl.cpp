#include "gtest/gtest.h"
#include <vector>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>

using namespace std;

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

class TestAlgorithmStl : public testing::Test
{
    void SetUp() {}

    void TearDown() {}
};

TEST_F(TestAlgorithmStl, test_for_transform_common)
{
    std::vector<int> container = {1, 2, 3, 4, 5};
    std::vector<int> destination = {};
    std::transform(container.begin(), container.end(), container.begin(), [](const auto &elem)
                   { return elem * 2; });
    std::vector<int> target = {2, 4, 6, 8, 10};
    EXPECT_EQ(container, target);
}

TEST_F(TestAlgorithmStl, test_for_max_min_element)
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

TEST_F(TestAlgorithmStl, test_for_find_if)
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

TEST_F(TestAlgorithmStl, test_for_for_each)
{
    std::vector<int> v{3, -4, 2, -8, 15, 267};

    auto print = [](const int &n)
    { std::cout << n << ' '; };

    std::cout << "before: ";
    std::for_each(v.cbegin(), v.cend(), print);
    std::cout << '\n';

    // 就地自增每个元素
    std::for_each(v.begin(), v.end(), [](int &n)
                  { n++; });

    std::cout << "after: ";
    std::for_each(v.cbegin(), v.cend(), print);
    std::cout << '\n';

    struct Sum
    {
        void operator()(int n) { sum += n; }
        int sum{0};
    };

    // 对每个元素调用 Sum::operator()
    Sum s = std::for_each(v.begin(), v.end(), Sum());
    std::cout << "总和：" << s.sum << '\n';
}