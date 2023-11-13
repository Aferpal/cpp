#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__
#include <exception>
class IllegalBalanceException: public std::exception
{
public:
    IllegalBalanceException() {}
    ~IllegalBalanceException() {}
    virtual const char* what() noexcept;
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
