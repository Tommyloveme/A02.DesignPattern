#include <iostream>
#include <map>
#include "gtest/gtest.h"

class Example {
private:
    unsigned int value;

public:
    Example(unsigned int val) : value(val) {}

    // 重载前缀递减运算符
    Example& operator--() {
        if (value > 0) {
            --value;
        }
        return *this;
    }

    // 重载前缀递减运算符
    Example& operator++() {
        ++value;
        return *this;
    }

    // 获取当前值
    unsigned int getValue() const {
        return value;
    }

    // 定义迭代器类
    class iterator {
    private:
        Example& ex;

    public:
        iterator(Example& e) : ex(e) {}

        // 重载解引用运算符
        unsigned int operator*() const {
            return ex.getValue();
        }

        // 重载前置递减运算符
        iterator& operator--() {
            --ex;
            return *this;
        }

        // 重载后置递减运算符
        iterator operator--(int) {
            iterator temp = *this;
            --ex;
            return temp;
        }

        // 重载前置递减运算符
        iterator& operator++() {
            ++ex;
            return *this;
        }

        // 重载后置递减运算符
        iterator operator++(int) {
            iterator temp = *this;
            ++ex;
            return temp;
        }

        // 重载不等于运算符
        bool operator!=(const iterator& other) const {
            return ex.getValue() != other.ex.getValue();
        }

        // 重载等于运算符
        bool operator==(const iterator& other) const {
            return ex.getValue() == other.ex.getValue();
        }
    };

    // 返回起始迭代器
    iterator begin() {
        return iterator(*this);
    }

    // 返回结束迭代器
    iterator end() {
        return iterator(*this);
    }
};

TEST(TestOperatorOverloading, unsigned_overrange)
{
    Example ex(10);

    // 使用逆序遍历
    for (auto it = --ex.end(); it != ex.begin(); --it) {
        std::cout << "Current value: " << *it << std::endl;
        // 在此处执行其他操作
    }

    for (auto val : ex) {
        std::cout << "Current value: " << val << std::endl;
        // 在此处执行其他操作
    }
    std::cout << "end" << std::endl;
}