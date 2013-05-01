#include <stdio.h>
#include "Bank.h"
#include <string>
using namespace std;
#include <cassert>
#include <iostream>

int main()
{
    Teller A("teller1");
    Bank bank("CS Minibank", A);

    string aliceName("Alice"), aliceID("C123456789");
    string bobName("Bob"), bobID("D987654321");
    string carolName("Carol"), carolID("A123454321");

    int aliceAccID = A.createAccount(bank, aliceName, aliceID);
    int bobAccID = A.createAccount(bank, bobName, bobID);
    int carolAccID = A.createAccount(bank, carolName, carolID);

    assert(!bank.deposit(aliceAccID, 5000));
    assert(!bank.withdraw(aliceAccID, 5000));
    assert(bank.inquire(aliceAccID) < 0); 

    assert(aliceAccID = bank.createAccount(aliceName, aliceID));
    assert(bank.inquire(aliceAccID) == 0);
    assert(bank.deposit(aliceAccID, 10000));
    assert(bank.inquire(aliceAccID) == 10000);

    assert(bobAccID = bank.createAccount(bobName, bobID));
    assert(bank.deposit(bobAccID, 23400));
    assert(bank.inquire(bobAccID) == 23400);

    assert(carolAccID = bank.createAccount(carolName, carolID));
    assert(bank.deposit(carolAccID, 53500));
    assert(bank.inquire(carolAccID) == 53500);

    assert(bank.withdraw(bobAccID, 3400));
    assert(bank.inquire(bobAccID) == 20000);

    assert(bank.transfer(carolAccID, aliceAccID, 13500));
    assert(bank.inquire(carolAccID) == 40000);
    assert(bank.inquire(aliceAccID) == 23500);

    assert(!bank.transfer(carolAccID, bobAccID, 50000));
    assert(!bank.withdraw(aliceAccID, 33500));

    assert(bank.withdraw(aliceAccID, 8500));
    assert(bank.inquire(aliceAccID) == 15000);

    assert(bank.dailyAudit());

    cout << "All tests passed." << endl;

    return 0;
}