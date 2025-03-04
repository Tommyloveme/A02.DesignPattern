#ifndef IBASE_H
#define IBASE_H

#include <memory>

class IBase
{
public:
    virtual void Execute1() = 0;
    virtual void Execute2() = 0;
    virtual ~IBase() = default;
};

// 声明工厂函数，外部通过工厂函数创建对象
template <typename T>
std::shared_ptr<IBase> CreateObject(T num);

#endif // IBASE_H
