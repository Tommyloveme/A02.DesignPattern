#include "TestBoost.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <variant>
#include <type_traits>
#include <tuple>
#include <map>
#include <string>
#include "boost/variant.hpp"
#include "gtest/gtest.h"

// 抽象的 Data 类
class Data {
public:
    // 构造函数，传入允许执行 Clear 动作的状态列表
    Data(const std::vector<char>& clearStates) : clearStates(clearStates) {}

    // 抽象的 Clear 方法
    virtual void Clear() = 0;

    // 判断是否在当前状态下执行 Clear 动作
    bool ShouldClear(char currentState) const {
        for (char state : clearStates) {
            if (state == currentState) {
                return true;
            }
        }
        return false;
    }

protected:
    std::vector<char> clearStates; // 允许执行 Clear 动作的状态列表
};

// 具体的 Data 的子类
class MyData : public Data {
public:
    MyData(const std::vector<char>& clearStates) : Data(clearStates) {}

    // 重载 Clear 方法
    virtual void Clear() override {
        std::cout << "Clearing MyData" << std::endl;
        // 在这里添加清理 MyData 的操作
    }
};

// 管理类 Manager
class Manager {
public:
    // 注册 Data 的子类
    void RegisterData(std::shared_ptr<Data> data) {
        dataList.push_back(data);
    }

    // 根据当前状态执行 Clear 动作
    void ClearForState(char currentState) {
        for (auto& data : dataList) {
            if (data->ShouldClear(currentState)) {
                data->Clear();
            }
        }
    }

private:
    std::vector<std::shared_ptr<Data>> dataList; // 存储注册的 Data 实例
};



class TestLifeCycle : public testing::Test
{
    void SetUp() {}

    void TearDown() {}
};


TEST_F(TestLifeCycle, base)
{
    // 创建 Manager 实例
    Manager manager;

    // 创建 MyData 实例并注册到 Manager
    std::shared_ptr<MyData> myData = std::make_shared<MyData>(std::vector<char>{'A', 'B'});
    manager.RegisterData(myData);

    // 模拟状态切换，执行 Clear 动作
    manager.ClearForState('A');
}