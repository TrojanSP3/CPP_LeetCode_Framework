#ifndef EXAMPLEPROBLEM_H
#define EXAMPLEPROBLEM_H

#include "../TestFramework/problem.h"
#include "../TestFramework/testlist.h"

namespace Problems
{
    class ExampleProblem: public Problem<int>
    {
    protected:
        virtual void solve();
    private:
        int sum(int a, int b);
    };

    class ExampleProblem2: public Problem<std::vector<int>>
    {
    protected:
        virtual void solve();
    private:
        std::vector<int> combine(int a, int b);
    };
}
namespace TestLists
{
    class ExampleProblemTestList: public TestList
    {
    public:
        static void runAll();
    protected:
        static Problems::ExampleProblem problem;
        static Problems::ExampleProblem2 problem2;
    private:
        static void exception();
        static void normal();
        static void vector();
    };
}
#endif // EXAMPLEPROBLEM_H
