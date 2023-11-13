#include "InsufficentFundsException.h"

const char* InsufficentFundsException::what() noexcept{
    return "Insufficient Funds to withdraw from Account ";
}