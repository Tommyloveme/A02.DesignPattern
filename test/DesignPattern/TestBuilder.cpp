#include <iostream>
#include <memory>
#include <string>

// 产品类：Car
class Car {
private:
    std::string engine;
    std::string wheels;
    std::string color;
public:
    void setEngine(const std::string& e) { engine = e; }
    void setWheels(const std::string& w) { wheels = w; }
    void setColor(const std::string& c) { color = c; }

    void showCar() {
        std::cout << "Car with Engine: " << engine << ", Wheels: " << wheels << ", Color: " << color << std::endl;
    }
};

// 生成器接口
class CarBuilder {
public:
    virtual void buildEngine() = 0;
    virtual void buildWheels() = 0;
    virtual void buildColor() = 0;
    virtual std::shared_ptr<Car> getCar() = 0;
    virtual ~CarBuilder() = default;
};

// 具体生成器：SportsCarBuilder
class SportsCarBuilder : public CarBuilder {
private:
    std::shared_ptr<Car> car;
public:
    SportsCarBuilder() { car = std::make_shared<Car>(); }
    void buildEngine() override { car->setEngine("V8 Turbo"); }
    void buildWheels() override { car->setWheels("Sports Wheels"); }
    void buildColor() override { car->setColor("Red"); }
    std::shared_ptr<Car> getCar() override { return car; }
};

// 具体生成器：SUVCarBuilder
class SUVCarBuilder : public CarBuilder {
private:
    std::shared_ptr<Car> car;
public:
    SUVCarBuilder() { car = std::make_shared<Car>(); }
    void buildEngine() override { car->setEngine("V6 Hybrid"); }
    void buildWheels() override { car->setWheels("Off-Road Wheels"); }
    void buildColor() override { car->setColor("Black"); }
    std::shared_ptr<Car> getCar() override { return car; }
};

// 指导者（Director）：控制建造流程
class CarDirector {
public:
    std::shared_ptr<Car> constructCar(CarBuilder& builder) {
        builder.buildEngine();
        builder.buildWheels();
        builder.buildColor();
        return builder.getCar();
    }
};

// 客户端代码
int main() {
    CarDirector director;

    // 生成一辆跑车
    SportsCarBuilder sportsCarBuilder;
    auto sportsCar = director.constructCar(sportsCarBuilder);
    sportsCar->showCar();

    // 生成一辆SUV
    SUVCarBuilder suvCarBuilder;
    auto suvCar = director.constructCar(suvCarBuilder);
    suvCar->showCar();

    return 0;
}
