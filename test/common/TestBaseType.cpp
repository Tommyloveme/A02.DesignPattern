#include "BaseType.h"
#include "TestBoost.h"
#include <iostream>
#include "gtest/gtest.h"

using namespace testBoost;

class TestBaseType : public testing::Test
{
    void SetUp() {}

    void TearDown() {}
};

TEST_F(TestBaseType, base)
{
    LinkedList<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);
    std::cout << list << std::endl;
    printf("%s\n", TOCHAR(list));
}