#include "gtest/gtest.h"

class TestClass : public testing::Test
{
    void SetUp() {}

    void TearDown() {}
};

class Base {
public:
    Base() { std::cout << "Constructing Base\n"; }
    ~Base() { std::cout << "Destructing Base\n"; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Constructing Derived\n"; }
    ~Derived() { std::cout << "Destructing Derived\n"; }
};

TEST_F(TestClass, construct_and_destruction_in_inheritance)
{
    Derived derivedObj;
}

#define TRACE_FUNCTION() TraceFunction tracer(__FUNCTION__)

class TraceFunction {
public:
    TraceFunction(const char* funcName) : functionName(funcName) {
        std::cout << "Entering function: " << functionName << std::endl;
    }

    ~TraceFunction() {
        std::cout << "Exiting function: " << functionName << std::endl;
    }

private:
    const char* functionName;
};

void func1() {
    TRACE_FUNCTION();

    // Your function code here
}

void func2() {
    TRACE_FUNCTION();

    // Your function code here
    func1();
}

TEST_F(TestClass, function_call_stack)
{
    func1();
    func2();
}