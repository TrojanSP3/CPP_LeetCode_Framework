#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>
#include <vector>
#include <sstream>

#include "comparator.h"
#include "testexception.h"
#include "timer.h"
#include "tostring.h"

namespace Problems
{

    template <class ResultType> class Problem
    {
    public:
        Problem();
        virtual ~Problem();
        void setArgs(std::vector<void *>* args);
        void run(ResultType* expected);
    protected:
        virtual void solve() = 0;
        std::vector<void*>* args;
        ResultType solution;
    private:
        int runCounter;
    };
}

namespace Problems
{
    template <class ResultType>
    Problem<ResultType>::Problem(): runCounter(0)
    {
    }

    template <class ResultType>
    Problem<ResultType>::~Problem()
    {
    }

    template <class ResultType>
    void Problem<ResultType>::setArgs(std::vector<void *>* args)
    {
        this->args=args;
    }

    template <class ResultType>
    void Problem<ResultType>::run(ResultType* expected)
    {
        runCounter++;
        std::cout<<"Test begin "<<runCounter<<std::endl;

        Timer timer;
        timer.start();
        this->solve();
        timer.stop();
        bool valid = compare<ResultType>(&solution,expected);

        std::cout<<"Test end. "<<timer.toString()<<std::endl<<std::endl;

        if(!valid)
        {
            std::stringstream ss;
            ss<<"Different answer!"<<std::endl;
            ss<<"Expected:"<<std::endl;
            if(expected!=nullptr)
                ss<<toString(*expected);
            else
                ss<<"nullptr";
            ss<<std::endl;
            ss<<"result:"<<std::endl;
            ss<<toString(solution)<<std::endl;
            TestException exception(ss.str(),"",0);
            throw exception;
        }
    }
}


#endif // PROBLEM_H
