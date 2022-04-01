#ifndef COMPARATOR_H
#define COMPARATOR_H

template <typename T> static bool compare(void* result, void* expected)
{
    if(result==nullptr)
        return false;
    if(expected==nullptr)
        return true;
    if(result==expected)
        return true;
    return (*(static_cast<T*>(result)))==(*(static_cast<T*>(expected)));
}

#endif // COMPARATOR_H
