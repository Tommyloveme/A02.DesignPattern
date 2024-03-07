#ifndef ENUM_DEFINE2_HEADER
#define ENUM_DEFINE2_HEADER

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

enum class Enum2 {
    Value1,
    Value2,
    Value3
};

template<>
inline std::string testBoost::ToString<Enum2>(const Enum2& enumValue) {
    switch (enumValue) {
        case Enum2::Value1:
            return "Enum2 Custom String for Value1";
        case Enum2::Value2:
            return "Enum2 Custom String for Value2";
        case Enum2::Value3:
            return "Enum2 Custom String for Value3";
        default:
            return "Unknown Enum Value";
    }
}

#endif // ENUM_DEFINE2_HEADER