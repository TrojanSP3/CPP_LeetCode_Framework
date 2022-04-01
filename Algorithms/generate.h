#ifndef GENERATE_H
#define GENERATE_H

#include <algorithm>
#include <climits>
#include <cstdint>
#include <cmath>
#include <random>
#include <vector>

namespace Algorithms
{
    template<typename T>
    class Generate
    {
        Generate()=delete;
    public:
        static T getRandomValue(int min=INT_MIN, int max=INT_MAX);
        static std::vector<T> getRandomArray
            (size_t size, int min=INT_MIN, int max=INT_MAX);
        static std::vector<T> getSortedArray
            (size_t size, int min=INT_MIN, int max=INT_MAX);
        static std::vector<T> getReversedSortedArray
            (size_t size, int min=INT_MIN, int max=INT_MAX);

    };
}
#endif // GENERATE_H
