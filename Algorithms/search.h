#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <sys/types.h>

namespace Algorithms
{
    template<typename T>
    class Search
    {
        Search()=delete;
    public:
        typedef ssize_t(*function_t)(std::vector<T>&, T&);
        static bool testThisAlgorithm(function_t function);
        static ssize_t linear(std::vector<T>& arr, T& value);
    };

}

#include "TestFramework/tostring.h"
#include <iostream>

namespace Algorithms
{
    template<typename T>
    bool Search<T>::testThisAlgorithm(function_t function)
    {
        std::cout<<">>>Testing search algorithm"<<std::endl;
        std::vector<T> vector;
        ssize_t result, expected;
        T searchFor;

        vector = std::vector<T>{10,20,30,40,50,50,60,70,80,90};
        std::cout<<">Case: 10 positive numbers, exist"<<std::endl;
        searchFor=60;
        expected=6;
        result = function(vector,searchFor);
        if(result!=expected)
        {
            std::cout<<"!Wrong"<<std::endl;
            std::cout<<"vec: "<<toString(vector)<<std::endl;
            std::cout<<"val: "<<toString(searchFor)<<std::endl;
            std::cout<<"exp: "<<toString(expected)<<std::endl;
            std::cout<<"got: "<<toString(result)<<std::endl;
            return false;
        }

        std::cout<<">Case: 10 positive numbers, not exist"<<std::endl;
        searchFor=33;
        expected=-1;
        result = function(vector,searchFor);
        if(result!=expected)
        {
            std::cout<<"!Wrong"<<std::endl;
            std::cout<<"vec: "<<toString(vector)<<std::endl;
            std::cout<<"val: "<<toString(searchFor)<<std::endl;
            std::cout<<"exp: "<<toString(expected)<<std::endl;
            std::cout<<"got: "<<toString(result)<<std::endl;
            return false;
        }

        vector = std::vector<T>{5};
        std::cout<<">Edge case: 1 item, exist"<<std::endl;
        searchFor=5;
        expected=0;
        result = function(vector,searchFor);
        if(result!=expected)
        {
            std::cout<<"!Wrong"<<std::endl;
            std::cout<<"vec: "<<toString(vector)<<std::endl;
            std::cout<<"val: "<<toString(searchFor)<<std::endl;
            std::cout<<"exp: "<<toString(expected)<<std::endl;
            std::cout<<"got: "<<toString(result)<<std::endl;
            return false;
        }

        vector = std::vector<T>{5};
        std::cout<<">Edge case: 1 item, not exist"<<std::endl;
        searchFor=100;
        expected=-1;
        result = function(vector,searchFor);
        if(result!=expected)
        {
            std::cout<<"!Wrong"<<std::endl;
            std::cout<<"vec: "<<toString(vector)<<std::endl;
            std::cout<<"val: "<<toString(searchFor)<<std::endl;
            std::cout<<"exp: "<<toString(expected)<<std::endl;
            std::cout<<"got: "<<toString(result)<<std::endl;
            return false;
        }

        std::cout<<">Edge case: 0 item"<<std::endl;
        vector.clear();
        searchFor=100;
        expected=-1;
        result = function(vector,searchFor);
        if(result!=expected)
        {
            std::cout<<"!Wrong"<<std::endl;
            std::cout<<"vec: "<<toString(vector)<<std::endl;
            std::cout<<"val: "<<toString(searchFor)<<std::endl;
            std::cout<<"exp: "<<toString<>(expected)<<std::endl;
            std::cout<<"got: "<<toString<>(result)<<std::endl;
            return false;
        }

        std::cout<<"Success"<<std::endl;
        return true;
    }

    template<typename T>
    ssize_t Search<T>::linear(std::vector<T>& arr, T& value)
    {
        size_t result;
        for(result=0;result<arr.size();++result)
        {
            if(arr[result]==value)
                break;
        }
        if(result==arr.size())
            return -1;
        else
            return static_cast<ssize_t>(result);
    }
}

#endif // SEARCH_H
