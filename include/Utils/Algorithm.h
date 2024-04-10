#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
#include "TestBoost.h"

namespace Utils {
    using namespace testBoost;

    template <typename T>
    T ElementSum(const std::vector<T> &vec)
    {
        if (vec.empty()) {
            return std::numeric_limits<T>::max();
        }
        return std::accumulate(vec.begin(), vec.end(), T{}, std::plus<T>());
    }

    template <typename T, typename ValueType, typename Func>
    T ElementSum(const std::vector<ValueType>& vec, Func func)
    {
        T sum {};
        for (const auto& it : vec) {
            sum += func(it);
        }
        return sum;
    }

    template <typename T>
    double ElementAve(const std::vector<T> &vec)
    {
        if (vec.empty()) {
            return NAN;
        }
        return static_cast<double>(ElementSum(vec)) / vec.size();
    }

    template <typename T, typename Func>
    double ElementAve(const std::vector<T> &originVec, Func func)
    {
        if (originVec.empty()) {
            return NAN;
        }
        std::vector<T> selectedVec;
        std::copy_if(originVec.begin(), originVec.end(), std::back_inserter(selectedVec), func);
        return static_cast<double>(ElementSum(selectedVec)) / selectedVec.size();
    }

    template <typename T>
    T ElementMax(const std::vector<T> &vec)
    {
        if (vec.empty()) {
            return std::numeric_limits<T>::max();
        }
        return *std::max_element(vec.begin(), vec.end());
    }

    template <typename T>
    T ElementMin(const std::vector<T> &vec)
    {
        if (vec.empty()) {
            return std::numeric_limits<T>::max();
        }
        return *std::min_element(vec.begin(), vec.end());
    }

} // namespace Utils
#endif // ALGORITHM_H