#include "gtest/gtest.h"
#include <string>

#include <iostream>
#include <string>
#include <memory>

class CommonParams {
public:
    int scanType;
    std::string scanName;
};

class SisScanParams : public CommonParams {
public:
    int sisMarkType;
    bool isAutoAlign;
};

class RasScanParams : public CommonParams {
public:
    double rasMarkType;
};

template <typename T>
class Measure {
public:
    void MeasureRequest() const;
    virtual ~Measure() = default;

protected:
    virtual int GetMarkType() const = 0;
};

template <typename T>
void Measure<T>::MeasureRequest() const
{
    std::cout << "Measure Request" << std::endl;
    std::cout << "Mark Type: " << GetMarkType() << std::endl;
}

class MeasureSis : public Measure<SisScanParams> {
public:
    MeasureSis() = default;
    MeasureSis(SisScanParams scanParams) : params(scanParams) {}

protected:
    int GetMarkType() const override
    {
        std::cout << "Measure Sis" << std::endl;
        return 1;
    }

    SisScanParams params;
};

class MeasureRas : public Measure<RasScanParams> {
public:
    MeasureRas() = default;
    MeasureRas(RasScanParams scanParams) : params(scanParams) {}
    int GetMarkType() const override
    {
        std::cout << "Measure Ras" << std::endl;
        return 2;
    }

    RasScanParams params;
};

template <typename T>
std::unique_ptr<Measure<T>> CreateFunctionFactory(T params) {
    if constexpr (std::is_same_v<T, SisScanParams>) {
        return std::make_unique<MeasureSis>(params);
    } else if constexpr (std::is_same_v<T, RasScanParams>) {
        return std::make_unique<MeasureRas>(params);
    } else {
        static_assert(sizeof(T) == 0, "Unknown scanParams!");
        return nullptr;
    }
}

enum class SensorTypeRAS {};
enum class SensorTypeSIS {};

template <typename SensorType>
auto CreateFunctionFactory()
{
    if constexpr (std::is_same_v<SensorType, SensorTypeSIS>) {
        return std::make_unique<MeasureSis>();
    } else if constexpr (std::is_same_v<SensorType, SensorTypeRAS>) {
        return std::make_unique<MeasureRas>();
    } else {
        static_assert(sizeof(SensorType) == 0, "Unknown SensorType!");
        return nullptr;
    }
}

TEST(TestClass, test)
{
    SisScanParams sisScanParams {};
    RasScanParams rasScanParams {};

    auto MeasureSis = CreateFunctionFactory<SensorTypeSIS>();
    if (MeasureSis) {
        MeasureSis->MeasureRequest();  // 正常调用
    }

    auto MeasureRas = CreateFunctionFactory(rasScanParams);
    if (MeasureRas) {
        MeasureRas->MeasureRequest();  // 正常调用
    }

    // 错误类型调用：编译时会报错
    // auto factoryInvalid = CreateFunctionFactory<SisScanParams>();  
    // factoryInvalid->Measure(MeasureRas);  // 编译时错误: RasScanParams 不是 SisScanParams 类型
}
