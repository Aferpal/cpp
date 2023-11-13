#include "Savings_Account.h"

class Trust_Account:public Savings_Account{
    private:
     static constexpr double bonusDeposit=50.00;
     static constexpr int maxWithdrawNumber=3;
     static constexpr double maxWithdrawPercentByBalance=0.2;
     static constexpr double bonusDepositFloor=5000.00;
     static constexpr const char* def_name="Defautl Trust Account";
    protected:
        int withdrawalN;
    public:
        Trust_Account(std::string name=def_name, double balance, double int_rate);
        bool deposit(double amount);
        bool withdraw(double amount);
};