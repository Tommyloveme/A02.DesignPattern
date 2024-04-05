#include "gtest/gtest.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>

#define TRACE() Trace trace = Trace(__func__);

using namespace std;

class Trace {
public:
    Trace(std::string funcName) : m_funcName(funcName)
    {
        std::cout << "--> " << funcName << "()" << endl;
    }

    ~Trace()
    {
        std::cout << "<-- " << m_funcName << "()" << endl;
    }
protected:
    std::string m_funcName;
};

// 前向声明
class MyData;

// 管理类 Manager
class Manager {
public:
    // 注册 Data 的子类
    void RegisterData(std::shared_ptr<MyData> data);

    // 获取 MyData 成员变量的接口
    int GetMyDataValue(std::shared_ptr<MyData> data) const;

    // 设置 MyData 成员变量的接口
    void SetMyDataValue(std::shared_ptr<MyData> data, int value);

private:
    std::vector<std::shared_ptr<MyData>> dataList; // 存储注册的 MyData 实例
};

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

// MyData 类
class MyData : public Data {
public:
    MyData(const std::vector<char>& clearStates) : Data(clearStates), value(0) {}

    // 重载 Clear 方法
    virtual void Clear() override {
        std::cout << "Clearing MyData" << std::endl;
        // 在这里添加清理 MyData 的操作
        value = 0;
    }

    // 友元声明
    friend class Manager;

private:
    int value; // MyData 的成员变量
};

// 注册 Data 的子类
void Manager::RegisterData(std::shared_ptr<MyData> data) {
    dataList.push_back(data);
}

// 获取 MyData 成员变量的接口
int Manager::GetMyDataValue(std::shared_ptr<MyData> data) const {
    return data->value;
}

// 设置 MyData 成员变量的接口
void Manager::SetMyDataValue(std::shared_ptr<MyData> data, int value) {
    data->value = value;
}

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

    // 设置和获取 MyData 的成员变量值
    manager.SetMyDataValue(myData, 42);
    std::cout << "MyData value: " << manager.GetMyDataValue(myData) << std::endl;
}

class EhcData {
public:
    static EhcData& Instance()
    {
        TRACE()
        static EhcData ehcData {};
        return ehcData;
    }

    friend ostream& operator<<(ostream& os, const EhcData& self)
    {
        os << "{id:" << self.m_id << ", name:" << self.m_name << "}" << endl;
        return os;
    }

protected:
    EhcData() = default;
    EhcData(EhcData&) = delete;
    EhcData operator=(EhcData&) = delete;
    int m_id = 0;
    string m_name{"undefined"};
    friend class EhcDataIntf;
};

struct Message {
    int id {0};
    string name {"undefined"};

    friend ostream& operator<<(ostream& os, const Message& self)
    {
        os << "{id:" << self.id << ", name:" << self.name << "}" << endl;
        return os;
    }
};

struct EhcDataIntf {
public:
    EhcDataIntf()
    {
        TRACE()
    }

    ~EhcDataIntf()
    {
        TRACE()
    }

    static const Message& GetMessage() noexcept;
    template<typename setterFunc>
    static void UpdateMessage(const setterFunc& setter) noexcept;

protected:
    static void SetMessage(const Message& message) noexcept;
};

const Message& EhcDataIntf::GetMessage() noexcept
{
    TRACE()
    static Message message;
    message.id = EhcData::Instance().m_id;
    message.name = EhcData::Instance().m_name;
    return message;
}

void EhcDataIntf::SetMessage(const Message& message) noexcept
{
    TRACE()
    EhcData& data = EhcData::Instance();
    data.m_id = message.id;
    data.m_name = message.name;
}

template<typename setterFunc>
void EhcDataIntf::UpdateMessage(const setterFunc& setter) noexcept
{
    TRACE()
    if constexpr(std::is_same_v<setterFunc, Message>) {
        SetMessage(setter);
    } else {
        Message message = GetMessage();
        setter(message);
        SetMessage(message);
    }
}

TEST(TestWorker, common)
{
    // Message message = EhcDataIntf::GetMessage();
    // auto id = EhcDataIntf::GetMessage().name;
    // cout << EhcData::Instance();

    Message message;
    message.id = 2;
    message.name = "dyl";
    EhcDataIntf::UpdateMessage(message);
    cout << EhcData::Instance();

    EhcDataIntf::UpdateMessage([](Message &message) {message.id = 3; });
    cout << EhcData::Instance();
}