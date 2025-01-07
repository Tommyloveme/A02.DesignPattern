#include <iostream>
#include <memory>
#include <string>
#include "gtest/gtest.h"

using namespace std;

// 抽象类：文本组件
class TextComponent {
public:
    virtual std::string render() const = 0; // 纯虚函数，用于渲染文本
    virtual ~TextComponent() = default;    // 虚析构函数
};

// 具体组件：基本文本
class PlainText : public TextComponent {
private:
    std::string text;
public:
    explicit PlainText(const std::string& text) : text(text) {}
    std::string render() const override {
        return text;
    }
};

// 抽象装饰器：装饰器基类
class TextDecorator : public TextComponent {
protected:
    std::shared_ptr<TextComponent> component; // 被装饰的文本组件
public:
    explicit TextDecorator(std::shared_ptr<TextComponent> component)
        : component(std::move(component)) {}
};

// 具体装饰器：加粗
class BoldDecorator : public TextDecorator {
public:
    explicit BoldDecorator(std::shared_ptr<TextComponent> component)
        : TextDecorator(std::move(component)) {}
    std::string render() const override {
        return "<b>" + component->render() + "</b>"; // 用HTML风格加粗
    }
};

// 具体装饰器：斜体
class ItalicDecorator : public TextDecorator {
public:
    explicit ItalicDecorator(std::shared_ptr<TextComponent> component)
        : TextDecorator(std::move(component)) {}
    std::string render() const override {
        return "<i>" + component->render() + "</i>"; // 用HTML风格斜体
    }
};

// 具体装饰器：下划线
class UnderlineDecorator : public TextDecorator {
public:
    explicit UnderlineDecorator(std::shared_ptr<TextComponent> component)
        : TextDecorator(std::move(component)) {}
    std::string render() const override {
        return "<u>" + component->render() + "</u>"; // 用HTML风格下划线
    }
};

class DecoratorPatternTest : public testing::Test {
public:
    DecoratorPatternTest() = default;
    ~DecoratorPatternTest() override = default;
};

TEST_F(DecoratorPatternTest, testDecoratorPattern)
{
    auto plainText = std::make_shared<PlainText>("Hello, world!");
    std::cout << plainText->render() << std::endl; // 输出：Hello, world!
    auto boldText = std::make_shared<BoldDecorator>(plainText);
    std::cout << boldText->render() << std::endl; // 输出：<b>Hello, world!</b>
    auto italicText = std::make_shared<ItalicDecorator>(boldText);
    std::cout << italicText->render() << std::endl; // 输出：<i><b>Hello, world!</b></i>
    auto underlineText = std::make_shared<UnderlineDecorator>(italicText);
    EXPECT_EQ(underlineText->render(), "<u><i><b>Hello, world!</b></i></u>");
}