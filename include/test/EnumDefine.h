#ifndef ENUM_DEFINE_HEADER
#define ENUM_DEFINE_HEADER

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <type_traits>

#ifndef TEST_BOOST_HEADER
namespace testBoost
{
    template<typename T>
    inline std::string ToString(const T& enumValue);
} // namespace testBoost
#endif

enum class Enum1 {
    Value1,
    Value2,
    Value3
};

template<>
inline std::string testBoost::ToString<Enum1>(const Enum1& enumValue) {
    switch (enumValue) {
        case Enum1::Value1:
            return "Custom String for Value1";
        case Enum1::Value2:
            return "Custom String for Value2";
        case Enum1::Value3:
            return "Custom String for Value3";
        default:
            return "Unknown Enum Value";
    }
}

#endif // ENUM_DEFINE_HEADER