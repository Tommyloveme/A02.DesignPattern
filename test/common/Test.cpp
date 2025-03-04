#include "gtest/gtest.h"
#include <string>

#include <iostream>
#include <string>
#include <memory>

enum class SensorType {
    SIS = 0,
    RAS
};

class CommonParams {
public:
    virtual SensorType GetSensorType() = 0;

    int scanType;
    std::string scanName;
};

class SisScanParams : public CommonParams {
public:
    int sisMarkType;
    bool isAutoAlign;

    SensorType GetSensorType() override
    {
        return SensorType::SIS;
    }
};

class RasScanParams : public CommonParams {
public:
    double rasMarkType;

    SensorType GetSensorType() override
    {
        return SensorType::RAS;
    }
};

class Measure {
public:
    void MeasureRequest() const;
    virtual ~Measure() = default;

protected:
    virtual int GetMarkType() const = 0;
};

void Measure::MeasureRequest() const
{
    std::cout << "Measure Request" << std::endl;
    std::cout << "Mark Type: " << GetMarkType() << std::endl;
}

class MeasureSis : public Measure {
public:
    MeasureSis(SisScanParams scanParams) : params(scanParams) {}

protected:
    int GetMarkType() const override
    {
        std::cout << "Measure Sis" << std::endl;
        return 1;
    }

    SisScanParams params;
};

class MeasureRas : public Measure {
public:
    MeasureRas(RasScanParams scanParams) : params(scanParams) {}
    int GetMarkType() const override
    {
        std::cout << "Measure Ras" << std::endl;
        return 2;
    }

    RasScanParams params;
};

/* ************************** 方案一：模板 ************************** */
template<typename T>
std::unique_ptr<Measure> CreateFunctionFactory(T scanParams);

template<>
std::unique_ptr<Measure> CreateFunctionFactory(SisScanParams scanParams)
{
    return std::make_unique<MeasureSis>(scanParams);
}

template<>
std::unique_ptr<Measure> CreateFunctionFactory(RasScanParams scanParams)
{
    return std::make_unique<MeasureRas>(scanParams);
}

template <typename T>
std::unique_ptr<Measure> CreateFunctionFactory(T params) {
    if constexpr (std::is_same_v<T, SisScanParams>) {
        return std::make_unique<MeasureSis>(params);
    } else if constexpr (std::is_same_v<T, RasScanParams>) {
        return std::make_unique<MeasureRas>(params);
    } else {
        static_assert(sizeof(T) == 0, "Unknown scanParams!");
        return nullptr;
    }
}

/* ************************** 方案二：多态 ************************** */
std::unique_ptr<Measure> CreateFunctionFactory(SensorType scanType, std::shared_ptr<CommonParams> scanParams)
{
    if (scanType == SensorType::SIS && scanParams->GetSensorType() == SensorType::SIS) {
        SisScanParams sisScanParams {};
        return std::make_unique<MeasureSis>(sisScanParams);
    } else if (scanType == SensorType::RAS && scanParams->GetSensorType() == SensorType::RAS) {
        RasScanParams rasScanParams {};
        return std::make_unique<MeasureRas>(rasScanParams);
    } else {
        return nullptr;
    }
}

std::unique_ptr<Measure> CreateFunctionFactory(std::shared_ptr<CommonParams> scanParams)
{
    if (scanParams->GetSensorType() == SensorType::SIS) {
        SisScanParams sisScanParams {};
        return std::make_unique<MeasureSis>(sisScanParams);
    } else if (scanParams->GetSensorType() == SensorType::RAS) {
        RasScanParams rasScanParams {};
        return std::make_unique<MeasureRas>(rasScanParams);
    } else {
        return nullptr;
    }
}

TEST(TestClass, test)
{
    SisScanParams sisScanParams {};
    RasScanParams rasScanParams {};

    auto MeasureSis = CreateFunctionFactory(SensorType::SIS, std::make_shared<SisScanParams>(sisScanParams));
    MeasureSis->MeasureRequest();  // 正常调用

    auto MeasureRas = CreateFunctionFactory(SensorType::RAS, std::make_shared<RasScanParams>(rasScanParams));
    MeasureRas->MeasureRequest();  // 正常调用
}
