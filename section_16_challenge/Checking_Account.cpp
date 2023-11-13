#include "Checking_Account.h"

Checking_Account::Checking_Account(const std::string& name, const double& balance):Account(name, balance){

}

bool Checking_Account::withdraw(double amount) {
    amount+=fee;
    if(balance>amount){
        balance-=amount;
        return true;
    }else{
        return false;
    }
}
bool Checking_Account::deposit(double amount) {
    balance+=amount;
    return true;
}

void Checking_Account::print(std::ostream& os) const {
    os<<"Checking Account :"<<name<<", "<<balance<<"$\n";
}