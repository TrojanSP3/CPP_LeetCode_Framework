#include <iostream>

#include "main.h"
#include "problems.h"

#include "TestFramework/tostring.h"
#include "Algorithms/search.h"
#include "Algorithms/sort.h"

#include <assert.h>
#include <bitset>
#include <cstring>

void Main::run()
{
    using namespace TestLists;
    ExampleProblemTestList::runAll();

    /*
    Algorithms::Sort<int>::function_t function = Algorithms::Sort<int>::mergeSort;
    Algorithms::Sort<int>::testThisAlgorithm(function);
    //*/

    /*
    Algorithms::Search<int>::function_t function = Algorithms::Search<int>::linear;
    Algorithms::Search<int>::testThisAlgorithm(function);
    //*/
}

int main()
{
    int exit_code = EXIT_SUCCESS;
    try {
        Main::run();
    } catch (TestException& testException) {
        std::cerr<<std::endl
                <<"Test failed!"<<std::endl
                <<testException.what()<<std::endl;
        exit_code=EXIT_FAILURE;
    } catch (std::exception& unhandledException) {
        std::cerr<<std::endl
                <<"An exception occurred!"<<std::endl
                <<unhandledException.what()<<std::endl;
        exit_code=EXIT_FAILURE;
    } catch (...) {
        std::cerr<<std::endl
                <<"An error occurred!"<<std::endl;
        exit_code=EXIT_FAILURE;
    }

    if(exit_code==EXIT_SUCCESS){
        std::cout<<std::endl
                <<"Program finished correctly"<<std::endl;
    }else{
        std::cerr<<std::endl
                <<"Program finished abnormally"<<std::endl;
    }

    std::cout.flush();
    std::cerr.flush();
    return exit_code;
}
