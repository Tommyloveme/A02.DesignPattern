#include <gtest/gtest.h>

#include <iostream>
#include <memory>
#include <optional>
#include <type_traits>

// ScanType 枚举类型
enum ScanType {
    ScanType1,
    ScanType2,
    ScanType3,
    ScanType4,
};

// 扫描参数类型
struct ScanTimeA {
    int hour = 0;
    int minute = 0;
    int second = 0;
};

struct ScanTimeB {
    int hour = 0;
    int minute = 0;
};

struct ScanPositionA {
    int x = 0;
};

struct ScanPositionB {
    int x = 0;
    int y = 0;
};

struct ScanPositionC {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

// 统一封装扫描数据
struct ScanData {
    std::optional<ScanTimeA> timeA;
    std::optional<ScanTimeB> timeB;
    std::optional<ScanPositionA> positionA;
    std::optional<ScanPositionB> positionB;
    std::optional<ScanPositionC> positionC;

    // 构造函数支持不同类型的参数初始化
    ScanData() = default;
    ScanData(ScanPositionA posA) : positionA(posA) {}
    ScanData(ScanTimeA timeA) : timeA(timeA) {}
    ScanData(ScanPositionB posB) : positionB(posB) {}
    ScanData(ScanTimeB timeB) : timeB(timeB) {}
    ScanData(ScanPositionC posC) : positionC(posC) {}
};

// 扫描策略接口
class IScanStrategy {
public:
    virtual ~IScanStrategy() = default;
    
    // 通过类型推导来决定 scan() 函数的启用条件
    template <typename T>
    using enable_if_scan_type = std::enable_if_t<std::is_same_v<T, ScanData>, bool>;

    virtual bool scan(const ScanData& data) = 0;
};

// ScanType1 策略实现：仅允许 ScanPositionA 和 ScanTimeA
class ScanType1Strategy : public IScanStrategy {
public:
    bool scan(const ScanData& data) override {
        if (data.positionA && data.timeA) {
            std::cout << "ScanType1: ScanA(" << data.positionA->x << ") at "
                      << data.timeA->hour << ":" << data.timeA->minute << ":" << data.timeA->second << std::endl;
            return true;
        }
        std::cout << "ScanType1: Invalid parameters!" << std::endl;
        return false;
    }
};

// ScanType2 策略实现：仅允许 ScanPositionB 和 ScanTimeB
class ScanType2Strategy : public IScanStrategy {
public:
    bool scan(const ScanData& data) override {
        if (data.positionB && data.timeB) {
            std::cout << "ScanType2: ScanB(" << data.positionB->x << ", " << data.positionB->y << ") at "
                      << data.timeB->hour << ":" << data.timeB->minute << std::endl;
            return true;
        }
        std::cout << "ScanType2: Invalid parameters!" << std::endl;
        return false;
    }
};

// ScanType3 策略实现：仅允许 ScanPositionC
class ScanType3Strategy : public IScanStrategy {
public:
    bool scan(const ScanData& data) override {
        if (data.positionC) {
            std::cout << "ScanType3: ScanC(" << data.positionC->x << ", " << data.positionC->y << ", " << data.positionC->z << ")" << std::endl;
            return true;
        }
        std::cout << "ScanType3: Invalid parameters!" << std::endl;
        return false;
    }
};

// 扫描上下文
class ScanContext {
public:
    void setStrategy(std::unique_ptr<IScanStrategy> strategy) {
        strategy_ = std::move(strategy);
    }

    bool executeScan(const ScanData& data) {
        if (strategy_) {
            return strategy_->scan(data);
        }
        std::cout << "No strategy set!" << std::endl;
        return false;
    }

private:
    std::unique_ptr<IScanStrategy> strategy_;
};

// 根据 ScanType 创建策略
std::unique_ptr<IScanStrategy> createScanStrategy(ScanType scanType) {
    switch (scanType) {
        case ScanType1:
            return std::make_unique<ScanType1Strategy>();
        case ScanType2:
            return std::make_unique<ScanType2Strategy>();
        case ScanType3:
            return std::make_unique<ScanType3Strategy>();
        default:
            std::cout << "Unknown ScanType!" << std::endl;
            return nullptr;
    }
}

// 客户端代码
TEST(FactoryPatternTest, common)
{
    // 创建 ScanContext
    ScanContext context;

    // 创建 ScanType1 扫描策略
    auto strategy1 = createScanStrategy(ScanType1);
    context.setStrategy(std::move(strategy1));

    // 创建 ScanData 并填充参数
    ScanData data1(ScanPositionA{10});
    data1.timeA = ScanTimeA{12, 30, 45};

    // 执行 ScanType1 扫描
    context.executeScan(data1);

    // 创建 ScanType2 扫描策略
    auto strategy2 = createScanStrategy(ScanType2);
    context.setStrategy(std::move(strategy2));

    // 创建 ScanData 并填充其他参数
    ScanData data2(ScanPositionB{20, 30});
    data2.timeB = ScanTimeB{14, 45};

    // 执行 ScanType2 扫描
    context.executeScan(data2);

    // 创建 ScanType3 扫描策略
    auto strategy3 = createScanStrategy(ScanType3);
    context.setStrategy(std::move(strategy3));

    // 创建 ScanData 并填充 ScanPositionC
    ScanData data3(ScanPositionC{1.1, 2.2, 3.3});

    // 执行 ScanType3 扫描
    context.executeScan(data3);

    // 以下会导致编译错误：ScanType1 不允许 ScanPositionB 和 ScanTimeB
    ScanData data4(ScanPositionB{10, 20});
    data4.timeB = ScanTimeB{12, 30};
    context.executeScan(data4); // 编译失败，参数类型不匹配
}
