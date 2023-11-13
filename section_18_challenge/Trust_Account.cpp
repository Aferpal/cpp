#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    try : Savings_Account {name, balance, int_rate}, num_withdrawals {0}  {
        
}catch(IllegalBalanceException& ex){
    std::cerr<<ex.what()<<"at Trust Account "<<*this;
}

// Deposit additional $50 bonus when amount >= $5000
bool Trust_Account::deposit(double amount) {
    if (amount >= bonus_threshold)
        amount += bonus_amount;
    return Savings_Account::deposit(amount);
}
    
// Only allowed 3 withdrawals, each can be up to a maximum of 20% of the account's value
void Trust_Account::withdraw(double amount) {
    if (num_withdrawals >= max_withdrawals || (amount > balance * max_withdraw_percent)){
        std::cerr<<"Max withdrawals on trust account or more tgan 20% account's balance withdraw\n";
    }
    else {
        ++num_withdrawals;
        Savings_Account::withdraw(amount);
    }
}

void Trust_Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Trust Account: " << name << ": " << balance << ", " << int_rate 
        << "%, withdrawals: " << num_withdrawals <<  "]";
}

