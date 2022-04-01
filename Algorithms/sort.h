#ifndef SORTING_H
#define SORTING_H

#include <vector>

namespace Algorithms
{
    template<typename T>
    class Sort
    {
        Sort()=delete;
    private:
        static void merge
            (std::vector<T>& arr,std::size_t l,std::size_t c,std::size_t r);
    public:
        typedef void(*function_t)(std::vector<T>&);
        static bool testThisAlgorithm(function_t function);
        static void insertionSort(std::vector<T>& arr);
        static void mergeSort(std::vector<T>& arr);
    };
}

#include "Algorithms/generate.h"
#include "TestFramework/tostring.h"
#include <iostream>

namespace Algorithms
{
    template<typename T>
    bool Sort<T>::testThisAlgorithm(function_t function)
    {
        std::cout<<">>>Testing sort algorithm"<<std::endl;
        std::vector<T> vecAlg, vecStd;

        std::cout<<">Case: 10 positive numbers"<<std::endl;
        vecAlg = std::vector<T>{80,50,20,40,30,50,90,70,10,60};
        vecStd = vecAlg;
        std::sort(vecStd.begin(),vecStd.end());
        function(vecAlg);
        if(vecStd!=vecAlg)
        {
            std::cout<<"!Wrong"<<std::endl;
            std::cout<<"std: "<<toString(vecStd)<<std::endl;
            std::cout<<"alg: "<<toString(vecAlg)<<std::endl;
            return false;
        }

        std::cout<<">Edge case: 1 item"<<std::endl;
        vecAlg.clear();
        vecAlg.push_back(1);
        vecStd = vecAlg;
        function(vecAlg);
        if(vecStd!=vecAlg)
        {
            std::cout<<"!Wrong"<<std::endl;
            std::cout<<"std: "<<toString(vecStd)<<std::endl;
            std::cout<<"alg: "<<toString(vecAlg)<<std::endl;
            return false;
        }

        std::cout<<">Edge case: 0 item"<<std::endl;
        vecAlg.clear();
        vecStd = vecAlg;
        function(vecAlg);
        if(vecStd!=vecAlg)
        {
            std::cout<<"!Wrong"<<std::endl;
            std::cout<<"std: "<<toString(vecStd)<<std::endl;
            std::cout<<"alg: "<<toString(vecAlg)<<std::endl;
            return false;
        }

        std::cout<<"Success"<<std::endl;
        return true;
    }


    template<typename T>
    void Sort<T>::insertionSort(std::vector<T>& arr)
    {
        for(std::size_t j=1; j<arr.size();++j)
        {
            T key = arr[j];
            ssize_t i=static_cast<ssize_t>(j-1);

            while((i>0) && (arr[i]>key))
            {
                arr[i+1]=arr[i];
                i--;
            }
            arr[i+1]=key;
        }
    }

    template<typename T>
    void Sort<T>::merge
    (std::vector<T>& arr,std::size_t l,std::size_t c,std::size_t r)
    {

    }

    template<typename T>
    void Sort<T>::mergeSort(std::vector<T>& arr)
    {

    }
}
#endif // SORTING_H
