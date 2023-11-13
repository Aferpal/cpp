#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate):Savings_Account(name, balance, int_rate), withdrawalN{0}{}
bool Trust_Account::deposit(double amount){
    if(amount>=bonusDepositFloor){
        amount+=bonusDeposit;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount){
    if(withdrawalN<maxWithdrawNumber && amount<balance*maxWithdrawPercentByBalance){
        withdrawalN++;
        return Savings_Account::withdraw(amount);
    }else{
        return false;
    }
}

void Trust_Account::print(std::ostream& os)const{
    os<<"Trust Account: ["<<name<<", "<<balance<<"$, int_rate"<<int_rate<<"]\n";
}