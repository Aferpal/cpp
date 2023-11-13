#include "Account.h"

Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {
}

double Account::get_balance() const {
    return balance;
}

