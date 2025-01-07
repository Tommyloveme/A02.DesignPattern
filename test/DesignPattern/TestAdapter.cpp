#include <gtest/gtest.h>

// 目标接口 (Target)
class Target {
public:
    virtual std::string request() const = 0;
    virtual ~Target() = default;
};

// 需要适配的旧接口 (Adaptee)
class Adaptee {
public:
    std::string specificRequest() const {
        return "Adaptee: Specific Request";
    }
};

// 适配器 (Adapter)
class Adapter : public Target {
private:
    const Adaptee* adaptee; // 持有对 Adaptee 的引用
public:
    explicit Adapter(const Adaptee* adaptee) : adaptee(adaptee) {}
    std::string request() const override {
        // 将 Adaptee 的 specificRequest 转化为 Target 的 request 格式
        return "Adapter: Translated (" + adaptee->specificRequest() + ")";
    }
};

// 测试 Adaptee 的功能
TEST(AdapterPatternTest, AdapteeWorksCorrectly) {
    Adaptee adaptee;
    EXPECT_EQ(adaptee.specificRequest(), "Adaptee: Specific Request");
}

// 测试 Adapter 的功能
TEST(AdapterPatternTest, AdapterTranslatesRequest) {
    Adaptee adaptee;
    Adapter adapter(&adaptee);

    // Adapter 应该正确地适配 Adaptee 的功能
    EXPECT_EQ(adapter.request(), "Adapter: Translated (Adaptee: Specific Request)");
}