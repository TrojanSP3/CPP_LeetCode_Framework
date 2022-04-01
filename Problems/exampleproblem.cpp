#include "Problems/exampleproblem.h"

#include <thread>
#include <chrono>

using namespace TestLists;
using namespace Problems;

ExampleProblem ExampleProblemTestList::problem;

void ExampleProblem::solve()
{
    int arg1 = *(static_cast<int*>(args->at(0)));
    int arg2 = *(static_cast<int*>(args->at(1)));
    solution = sum(arg1,arg2);
}

int ExampleProblem::sum(int a, int b)
{
    std::this_thread::sleep_for(std::chrono::milliseconds((33)));
    return a+b;
}

ExampleProblem2 ExampleProblemTestList::problem2;

void ExampleProblem2::solve()
{
    int arg1 = *(static_cast<int*>(args->at(0)));
    int arg2 = *(static_cast<int*>(args->at(1)));
    solution = combine(arg1,arg2);
}

std::vector<int> ExampleProblem2::combine(int a, int b)
{
    std::vector<int> result;
    result.push_back(a);
    result.push_back(b);
    return result;
}

void ExampleProblemTestList::runAll()
{
    std::cout<<std::endl<<">>>Normal group"<<std::endl;
    normal();

    std::cout<<std::endl<<">>>Vector group"<<std::endl;
    vector();

    std::cout<<std::endl<<">>>Exception group"<<std::endl;
    exception();
}


void ExampleProblemTestList::exception()
{
    std::vector<void* > args;
    problem.setArgs(&args);

    int arg1;
    int arg2;
    int expected;
    args.push_back(&arg1);
    args.push_back(&arg2);

    arg1=100;
    arg2=200;
    expected=arg1+arg2+1;

    bool ExceptionNotThrown = false;
    try
    {
        problem.run(&expected);
        ExceptionNotThrown=true;
        EXCEPTION("Exception must be thrown!");
    } catch (TestException&) {
        if(ExceptionNotThrown)
            throw;
    }
}


void ExampleProblemTestList::normal()
{
    std::vector<void* > args;
    problem.setArgs(&args);

    int arg1;
    int arg2;
    int expected;
    args.push_back(&arg1);
    args.push_back(&arg2);

    arg1=100;
    arg2=200;
    expected=arg1+arg2;

    problem.run(&expected);

    arg1=99;
    arg2=88;
    expected=arg1+arg2;

    problem.run(&expected);

    arg1=0;
    arg2=1;
    expected=arg1+arg2;

    problem.run(&expected);
}


void ExampleProblemTestList::vector()
{
    std::vector<void* > args;
    problem2.setArgs(&args);

    int arg1;
    int arg2;
    std::vector<int> expected;
    args.push_back(&arg1);
    args.push_back(&arg2);

    expected.clear();
    arg1=100;
    arg2=200;
    expected.push_back(arg1);
    expected.push_back(arg2);
    problem2.run(&expected);

    expected.clear();
    arg1=5;
    arg2=5;
    expected.push_back(arg1);
    expected.push_back(arg2);
    problem2.run(&expected);

    expected.clear();
    arg1=30;
    arg2=10;
    expected.push_back(arg1);
    expected.push_back(arg2);
    problem2.run(&expected);

}


