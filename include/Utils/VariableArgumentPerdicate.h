#ifndef VARIABLE_ARGUMENT_PREDICATE_H
#define VARIABLE_ARGUMENT_PREDICATE_H

namespace Utils
{

template<typename... Args>
inline bool AllTrue(Args... args)
{
    return (... && args);
}

template<typename... Args>
inline bool AllFalse(Args... args)
{
    return !(... || args);
}

} // namespace Utils
#endif // VARIABLE_ARGUMENT_PREDICATE_H