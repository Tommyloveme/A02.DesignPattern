#include <iostream>
#include <map>
#include <string>
#include "TestBoost.h"
#include "gtest/gtest.h"

using namespace testBoost;

template <typename T>
struct counter
{
    static int objects_created;
    static int objects_alive;

    counter()
    {
        ++objects_created;
        ++objects_alive;
    }
    
    counter(const counter&)
    {
        ++objects_created;
        ++objects_alive;
    }

protected:
    ~counter() // objects should never be removed through pointers of this type
    {
        --objects_alive;
    }
};

template <typename T> int counter<T>::objects_created(0);
template <typename T> int counter<T>::objects_alive(0);

class X : public counter<X>
{
    // ...
};

class Y : public counter<Y>
{
    // ...
};

template<typename T>
class Singleton {
public:
    static T& getInstance() {
        static T instance;
        return instance;
    }

    // 删除拷贝构造函数和赋值运算符，确保单例的唯一性
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

protected:
    Singleton() {} // 声明保护的构造函数，确保不能直接创建实例
};

// 示例：继承 Singleton 并使用
class MySingleton : public Singleton<MySingleton> {
    friend class Singleton<MySingleton>; // 允许基类调用保护构造函数

public:
    int m_id = 0;
    void doSomething() {
        std::cout << "Doing something..." << std::endl;
    }

protected:
    MySingleton() {} // 声明私有构造函数，确保不能直接创建实例
};


class TestSingleton : public testing::Test
{
    void SetUp() {}

    void TearDown() {}
};

TEST_F(TestSingleton, count_objects_created_alive)
{
    X x1;
    EXPECT_EQ(X::objects_created, 1);
    EXPECT_EQ(X::objects_alive, 1);

    {
        X x2;
        EXPECT_EQ(X::objects_created, 2);
        EXPECT_EQ(X::objects_alive, 2);
    }
    EXPECT_EQ(X::objects_created, 2);
    EXPECT_EQ(X::objects_alive, 1);

    Y y1;
    EXPECT_EQ(Y::objects_created, 1);
    EXPECT_EQ(Y::objects_alive, 1);
}

TEST_F(TestSingleton, test_class)
{
    MySingleton::getInstance();
}