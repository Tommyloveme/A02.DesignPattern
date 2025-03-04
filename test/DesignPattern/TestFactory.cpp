#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <gtest/gtest.h>

// 抽象基类 (Product)
class Shape {
public:
    virtual void draw() const = 0; // 抽象绘制方法
    virtual ~Shape() = default;
};

// 具体产品类 (Concrete Product)
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Rectangle\n";
    }
};

// 工厂基类 (Creator)
class ShapeFactory {
public:
    virtual std::unique_ptr<Shape> createShape() const = 0;
    virtual ~ShapeFactory() = default;
};

// 具体工厂类 (Concrete Creator)
class CircleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> createShape() const override {
        return std::make_unique<Circle>();
    }
};

class RectangleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> createShape() const override {
        return std::make_unique<Rectangle>();
    }
};

// 客户端代码
void drawShapes(const std::vector<std::unique_ptr<ShapeFactory>>& factories) {
    for (const auto& factory : factories) {
        auto shape = factory->createShape();
        shape->draw();
    }
}

TEST(FactoryPatternTest, common)
{
    std::vector<std::unique_ptr<ShapeFactory>> factories;
    factories.push_back(std::make_unique<CircleFactory>());
    factories.push_back(std::make_unique<RectangleFactory>());

    drawShapes(factories); // 动态调用绘制方法
}
