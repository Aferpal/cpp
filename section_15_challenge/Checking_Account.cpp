#include "Checking_Account.h"

Checking_Account::Checking_Account(const std::string& name, const double& balance):Account(name, balance){

}

bool Checking_Account::withdraw(double amount){
    amount+=fee;
    return Account::withdraw(amount);
}