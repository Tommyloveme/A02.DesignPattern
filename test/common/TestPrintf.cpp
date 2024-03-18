#include <gtest/gtest.h>
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <cstdarg>
#include <cmath>

TEST(TestPrintf, basic)
{
    int num = 123;
    double dbl = 456.789;

    for (int index = 10; index < 20; ++index) {
        // 左对齐，输出宽度为10
        printf("Left aligned: %-10d\n", index);

        // 带符号输出，+表示始终显示符号
        printf("With sign: %+d\n", index * (index % 2 ? 1 : -1));
    }

    // 若有符号，则在前面填充空格，但+标志会忽略空格
    printf("With space: % d\n", num);

    // 替用形式转换（仅对于八进制和十六进制有效），以0开头
    printf("Alternate form: %#o\n", num);
    printf("Alternate form: %#x\n", num);

    // 使用前导零填充
    printf("Zero padding: %010d\n", num);
    
    // 对于浮点数，也可以使用前导零填充，但精度会被忽略
    printf("Zero padding for double: %010.2f\n", dbl);

    // 指定最小字段宽度为10
    printf("Minimum width: %10d\n", num);
    
    // 使用 * 指定最小字段宽度
    printf("Minimum width with *: %*d\n", 10, num);

    // 使用负数的 * 指定左对齐
    printf("Left aligned with *: %-*d\n", 10, num);

    // 使用精度，限制浮点数输出到小数点后两位
    printf("Precision for double: %.2f\n", dbl);
    
    // 使用 * 指定精度
    printf("Precision with * for double: %.*f\n", 2, dbl);

    // 使用长度修饰符 h 和 l
    short shortNum = 123;
    long long longNum = 1234567890L;
    printf("Short number: %hd\n", shortNum);
    printf("Long number: %ld\n", longNum);
}

TEST(TestPrintf, snprintf)
{
    auto fmt = "sqrt(2) = %f";
    int sz = std::snprintf(nullptr, 0, fmt, std::sqrt(2));
    std::vector<char> buf(sz + 1); // 注意为空终止符 +1
    std::sprintf(buf.data(), fmt, std::sqrt(2)); // 确定可以放入
}