#include "gtest/gtest.h"
#include <string>

#include <iostream>
#include <memory>
#include <unordered_map>
#include <typeinfo>
#include <typeindex>

template <typename T>
class IBase
{
public:
    virtual void Execute1(T num) = 0;
    virtual void Execute2() = 0;
    virtual ~IBase() = default;
};

class Base1 : public IBase<int>
{
public:
    Base1(int num) { std::cout << "Base1 created with num = " << num << std::endl; }
    void Execute1() override { std::cout << "Base1::Execute1()" << std::endl; }
    void Execute2() override { std::cout << "Base1::Execute2()" << std::endl; }
};

struct Base2Msg {
    Base2Msg() = default;
    Base2Msg(Base2Msg& msg) {this->id = msg.id;}
    double id;
    std::string name;
};

class Base2 : public IBase
{
public:
    Base2(Base2Msg num) { std::cout << "Base2 created with num = " << num.id << std::endl; }
    void Execute1() override { std::cout << "Base2::Execute1()" << std::endl; }
    void Execute2() override { std::cout << "Base2::Execute2()" << std::endl; }
};

template <typename T>
class Factory
{
public:
    static std::shared_ptr<IBase> Create(T num);
};

template <>
std::shared_ptr<IBase> Factory<int>::Create(int num)
{
    return std::make_shared<Base1>(num);
}

template <>
std::shared_ptr<IBase> Factory<Base2Msg>::Create(Base2Msg num)
{
    return std::make_shared<Base2>(num);
}

class FactoryManager
{
public:
    // Template function to create and manage objects
    template <typename T>
    static std::shared_ptr<IBase> Create(T num)
    {
        std::shared_ptr<IBase> obj = Factory<T>::Create(num);
        objectStore[typeid(T)].push_back(obj);
        return obj;
    }

    // Retrieve the stored objects of a particular type
    template <typename T>
    static std::vector<std::shared_ptr<IBase>> GetObjects()
    {
        auto it = objectStore.find(typeid(T));
        if (it != objectStore.end())
        {
            return it->second;
        }
        else
        {
            return {};
        }
    }

    // Print stored objects for debugging purposes
    template <typename T>
    static void PrintObjects()
    {
        auto objects = GetObjects<T>();
        std::cout << "Objects of type " << typeid(T).name() << ":\n";
        for (auto& obj : objects)
        {
            obj->Execute1(); // You can also use Execute2() or any other method.
        }
    }

private:
    // Store objects in a map, using the type of the object as the key
    static std::unordered_map<std::type_index, std::vector<std::shared_ptr<IBase>>> objectStore;
};

// Definition of the static member
std::unordered_map<std::type_index, std::vector<std::shared_ptr<IBase>>> FactoryManager::objectStore;

{
    void Execute1(int num, int& action) {};
    void Execute2(int action, std::string& result) {};
    void Execute1(Base2Msg num, int& action) {};
    void Execute2(int action, std::string& result) {};
}

{
    void Execute1(int num, int& action) {};
    void Execute1(Base2Msg num, int& action) {};
    void Execute2(int action, int num) {};
    void Execute2(int action, Base2Msg num) {};
}

TEST(TestTemplate, test)
{
    // Create some objects using the FactoryManager
    Base2Msg msg;
    msg.id = 1;
    msg.name = "mike";
    auto obj1 = FactoryManager::Create(msg); // Should create Base2
    obj1->Execute1(); // Should print "Base1::Execute1()"

    msg.id = 2;
    msg.name = "max";
    auto obj2 = FactoryManager::Create(msg); // Should create Base2
    obj2->Execute1(); // Should print "Base1::Execute1()"
}

TEST(TestTemplate, expect)
{
    // Create some objects using the FactoryManager
    Base2Msg msg;
    msg.id = 1;
    msg.name = "mike";
    auto obj1 = FactoryManager::Create(msg); // Should create Base2
    obj1->Execute1(); // Should print "Base1::Execute1()"

    msg.id = 2;
    msg.name = "max";
    auto obj2 = FactoryManager::Create(msg); // Should create Base2
    obj2->Execute1(); // Should print "Base1::Execute1()"
}