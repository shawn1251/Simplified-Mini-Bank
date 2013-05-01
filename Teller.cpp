#include "Teller.h"
#include "Bank.h"

Teller::Teller(char name[])
    : m_startCash(200000), m_cash(m_startCash), m_name(name)
{
}


Teller::~Teller(void)
{
}


int Teller::createAccount(Bank bank, string& customerName, string& customerID)
{
	int accoutID = bank.createAccount(customerName, customerID);
	
	return accoutID;
}


bool Teller::deposit(Bank bank, int year, int month, int day, int accountID, int amount)
{
	if(bank.deposit(accountID, amount) == true)
		bank.MakeNode(year, month, day, accountID, accountID, amount);
}


int Teller::inquire(Bank bank, int accountID)
{
	bank.inquire(accountID);
}


bool Teller::withdraw(Bank bank, int year, int month, int day, int accountID, int amount)
{
	if(bank.withdraw(accountID, amount) == true)
		bank.MakeNode(year, month, day, accountID, accountID, amount*(-1));
}


bool Teller::transfer(Bank bank, int year, int month, int day, int accountID, int beneficiaryID, int amount)
{
	if(bank.transfer(accountID, beneficiaryID, amount) == true)	
		bank.MakeNode(year, month, day, accountID, beneficiaryID, amount);
}
