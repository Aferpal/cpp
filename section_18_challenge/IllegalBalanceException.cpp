#include "IllegalBalanceException.h"

const char* IllegalBalanceException::what() noexcept{
    return "Illegal Negative Value on Balance";
 } 