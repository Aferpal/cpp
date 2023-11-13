#include "Savings_Account.h"

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    try : Account {name, balance}, int_rate{int_rate} {
        
    }
    catch (IllegalBalanceException& ex) {
        std::cerr<<ex.what()<<"at Savings Account "<<*this;
    }
// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) 
//      and then the updated amount will be deposited
//
bool Savings_Account::deposit(double amount) {
    amount += amount * (int_rate/100);
    return Account::deposit(amount);
}

void Savings_Account::withdraw(double amount) {
    Account::withdraw(amount);
}


void Savings_Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Savings_Account: " << name << ": " << balance << ", " << int_rate << "]";
}
