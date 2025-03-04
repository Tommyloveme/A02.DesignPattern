#ifndef BASEIMPL_H
#define BASEIMPL_H

#include "IBase.h"
#include <iostream>

class Base1 : public IBase
{
public:
    Base1(int num) {}
    virtual void Execute1() override
    {
        std::cout << "Base1::Execute1()" << std::endl;
    }

    virtual void Execute2() override
    {
        std::cout << "Base1::Execute2()" << std::endl;
    }
};

class Base2 : public IBase
{
public:
    Base2(double num) {}
    virtual void Execute1() override
    {
        std::cout << "Base2::Execute1()" << std::endl;
    }

    virtual void Execute2() override
    {
        std::cout << "Base2::Execute2()" << std::endl;
    }
};

#endif // BASEIMPL_H
