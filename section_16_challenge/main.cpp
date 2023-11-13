// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
    Account* p1= new Savings_Account("John", 1000.0, 1.0);
    Account* p2= new Checking_Account("Hermione", 1000.0);
    Account* p3= new Trust_Account("Ronald", 2000.0, 1.0);

    vector<Account*> accounts={p1, p2, p3};
    display(accounts);
    deposit (accounts, 500.0);
    withdraw(accounts, 2000.0);
    display(accounts);
    delete p1;
    delete p2;
    delete p3;
    return 0;
}

