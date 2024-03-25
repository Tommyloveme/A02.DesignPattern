#ifndef CONDITIONAL_JUDGMENT_HEADER
#define CONDITIONAL_JUDGMENT_HEADER

#include <iostream>

namespace Judgment {

inline bool AllTrue(bool boolean)
{
    return boolean;
}

template<typename... Args>
inline bool AllTrue(bool boolean, Args... args)
{
    return boolean && AllTrue(args...);
}

} // namespace Judgment

#endif // CONDITIONAL_JUDGMENT_HEADER