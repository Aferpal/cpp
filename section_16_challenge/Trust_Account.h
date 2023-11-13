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
        Trust_Account(std::string name=def_name, double balance=0.0, double int_rate=0.0);
        virtual bool deposit(double amount) override;
        virtual bool withdraw(double amount) override;
        virtual void print(std::ostream& os)const override;
        virtual ~Trust_Account()=default;
};