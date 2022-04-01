#ifndef TOSTRING_H
#define TOSTRING_H

#include <string>
#include <sstream>
#include <vector>

template <typename T>
std::string toString(const T& obj)
{
    return std::to_string(obj);
}

template <typename T, typename A>
std::string toString(const std::vector<T,A>& obj)
{
    std::stringstream ss;
    ss<<"[";
    for(size_t i=0;i<obj.size();++i)
    {
        ss<<toString(obj[i]);
        if(i!=obj.size()-1)
            ss<<", ";
    }
    ss<<"]";
    return ss.str();
}

#endif // TOSTRING_H
