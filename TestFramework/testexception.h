#ifndef TESTEXCEPTION_H
#define TESTEXCEPTION_H

#include <exception>
#include <string>

#define EXCEPTION(message) \
{TestException _test_exception_macro((message), (__FILE__), (__LINE__)); throw _test_exception_macro;}

class TestException: public std::exception
{
public:
    TestException(std::string msg, std::string _file, int _line);
    virtual ~TestException();
    virtual const char* what() const noexcept;
private:
    std::string message;
};

#endif // TESTEXCEPTION_H
