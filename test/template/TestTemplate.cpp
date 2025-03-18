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

using namespace testBoost;
using namespace std;

#include <iostream>
#include <vector>
#include <string>

#include <iostream>
#include <vector>
#include <string>
#include <memory>

// 静态多态模板方法模式
template<typename T>
class Base {
public:
    void execute1(const typename T::T1& input, typename T::T2& output) {
        T::execute1Impl(input, output);
    }

    void execute2(const typename T::T3& input, typename T::T4& output) {
        T::execute2Impl(input, output);
    }
};

// 派生类，继承 Base<Derived>
class Derived1 {
public:
    using T1 = int;
    using T2 = double;
    using T3 = std::string;
    using T4 = std::vector<int>;

    static void execute1Impl(const T1& input, T2& output) {
        std::cout << "Derived1 execute1: " << input << std::endl;
        output = input * 2.0;
    }

    static void execute2Impl(const T3& input, T4& output) {
        std::cout << "Derived1 execute2: " << input << std::endl;
        output.push_back(42);
    }
};

class Derived2 {
public:
    using T1 = float;
    using T2 = std::map<int, double>;
    using T3 = char;
    using T4 = int;

    static void execute1Impl(const T1& input, T2& output) {
        std::cout << "Derived2 execute1: " << input << std::endl;
    }

    static void execute2Impl(const T3& input, T4& output) {
        std::cout << "Derived2 execute2: " << input << std::endl;
    }
};

Base<Derived1> CreateDerived1() {
    return Base<Derived1>();
}

Base<Derived2> CreateDerived2() {
    return Base<Derived2>();
}

int main() {
    auto d = CreateDerived1();

    Derived1::T1 t1 = 10;
    Derived1::T2 t2;
    d.execute1(t1, t2);
    std::cout << "Output of execute1: " << t2 << std::endl;

    Derived1::T3 t3 = "Hello";
    Derived1::T4 t4;
    d.execute2(t3, t4);
    std::cout << "Output of execute2: " << t4[0] << std::endl;

    return 0;
}
