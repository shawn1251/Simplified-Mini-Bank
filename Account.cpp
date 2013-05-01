#include "Account.h"
#include <cassert>

int Account::serialNo = 100;

Account::Account(string& customerName, string& customerID)
    : m_customerName(customerName), m_customerID(customerID),
      m_balance(0), m_accountID(serialNo++)
{
}


Account::~Account(void)
{
}


bool Account::isCustomerID(string& customerID)
{
    return false;
}


int Account::getAccountID(void)
{
    return m_accountID;
}


bool Account::isAccountID(int accountID)
{
    return accountID == m_accountID;
}


void Account::add(int amount)
{
    assert(m_balance+amount >= 0);
    m_balance += amount;
}


int Account::getBalance()
{
    return m_balance;
}
