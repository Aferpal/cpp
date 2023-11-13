#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    // test your code here
    Account* p1= new Savings_Account("Salvador", 1000.0, 2.5);
    Account* p2= new Checking_Account("Maria", 2000.00);
    Account* p3= new Trust_Account("Ivan", 5000.0, 3.0);
    std::vector<Account*> vec={p1, p2, p3};
    display(vec);
    deposit(vec, 1000.0);
    withdraw(vec, 500.0);
    
    withdraw(vec, 2000.0);
    
    
    delete p1;
    delete p2;
    delete p3;
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

