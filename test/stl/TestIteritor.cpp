#include "gtest/gtest.h"
#include <vector>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <forward_list>

using namespace std;

enum Name {
    NAME_MIN,
    John,
    Mary,
    Tom,
    Jane,
    Mark,
    Lisa,
    NAME_MAX
};

template<typename Enum>
class WeakEnum {
private:
    unsigned value;

public:
    // 构造函数
    WeakEnum(Enum e) : value(static_cast<unsigned>(e)) {}

    // 自减操作符
    WeakEnum& operator--() {
        if (value > 0) {
            --value;
        }
        return *this;
    }

    // 后置自减操作符
    WeakEnum operator--(int) {
        WeakEnum temp = *this;
        --(*this);
        return temp;
    }

    // 相等比较操作符
    bool operator==(const WeakEnum& other) const {
        return value == other.value;
    }

    // 不相等比较操作符
    bool operator!=(const WeakEnum& other) const {
        return value != other.value;
    }

    // 小于比较操作符
    bool operator<(const WeakEnum& other) const {
        return value < other.value;
    }

    // 大于比较操作符
    bool operator>(const WeakEnum& other) const {
        return value > other.value;
    }

    // 转换为 unsigned 类型
    operator unsigned() const {
        return value;
    }

    // 获取当前值
    unsigned get() const {
        return value;
    }
};

class TestIteritor : public testing::Test
{
    void SetUp() {}

    void TearDown() {}
};

/*
输入迭代器 主要用于一次性读取数据的场景，如输入流。
输出迭代器 主要用于一次性写入数据的场景，如输出流。
前向迭代器 可以多次读取同一元素，但只能向前遍历。
双向迭代器 允许双向遍历，但不支持随机访问。
随机访问迭代器 提供最灵活的操作，支持随机访问和双向遍历。
*/

TEST_F(TestIteritor, istream_iterator)
{
    std::cout << "Enter integers (end with non-integer): ";
    std::istream_iterator<int> inputIt(std::cin);
    std::istream_iterator<int> endIt;

    std::vector<int> numbers(inputIt, endIt);

    std::cout << "You entered: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

TEST_F(TestIteritor, ostream_iterator)
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::ostream_iterator<int> outputIt(std::cout, ", ");
    std::copy(numbers.begin(), numbers.end(), outputIt);
    std::cout << std::endl;
}

TEST_F(TestIteritor, forward_list)
{
    std::forward_list<int> flist = {1, 2, 3, 4, 5};

    for (auto it = flist.begin(); it != flist.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

TEST_F(TestIteritor, WeakEnum)
{
    WeakEnum<Name> name(Lisa);

    // for 循环使用 WeakEnum 实现递减
    for (WeakEnum<Name> i = name; i >= NAME_MIN; --i) {
        std::cout << i.get() << " ";
    }
    std::cout << std::endl;
}