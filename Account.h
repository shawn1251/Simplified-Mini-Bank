#pragma once

#include <string>
using namespace std;

class Account
{
public:
    Account(string& customerName, string& customerID);
    virtual ~Account(void);
    bool isCustomerID(string& customerID);
    int getAccountID(void);
    bool isAccountID(int accountID);
    void add(int amount);
    int getBalance();
private:
    string m_customerName;
    string m_customerID;
    int m_accountID;
    int m_balance;
    static int serialNo;
};

