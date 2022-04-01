#include "generate.h"

using namespace Algorithms;

template<typename T>
T Generate<T>::getRandomValue(int min, int max)
{
    const int INT_SHIFT = sizeof(int)*8/2;
    const unsigned int INT_MASK_L =
            static_cast<unsigned int>(std::pow(2,INT_SHIFT)-1);

    long intervalMax = static_cast<long>(1L + max - min );
    long intervalMin = static_cast<long>(min);

    unsigned int part1 = static_cast<unsigned int>(std::rand())
            & INT_MASK_L;
    unsigned int part2 = static_cast<unsigned int>(std::rand())
            & INT_MASK_L;
    unsigned int randValue = (part1 << INT_SHIFT) | part2;
    long value = randValue % intervalMax + intervalMin;
    return static_cast<T>(value);
}

template<typename T>
std::vector<T> Generate<T>::getRandomArray
    (size_t size, int min, int max)
{
    std::vector<T> result;
    result.reserve(size);
    for(size_t i=0;i<size;++i)
    {
        result.push_back(getRandomValue(min,max));
    }
    return result;
}

template<typename T>
std::vector<T> Generate<T>::getSortedArray
    (size_t size, int min, int max)
{
    std::vector<T> result = getRandomArray(size,min,max);
    std::sort(result.begin(),result.end());
    return result;
}

template<typename T>
std::vector<T> Generate<T>::getReversedSortedArray
    (size_t size, int min, int max)
{
    std::vector<T> result = getSortedArray(size,min,max);
    std::reverse(result.begin(),result.end());
    return result;
}
