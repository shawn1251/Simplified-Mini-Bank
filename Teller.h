#pragma once
#include <string>
using namespace std;

// Forward declaration
class Bank;

class Teller
{
	friend Bank;
	public:
		Teller(char name[]);
		virtual ~Teller(void);
		int createAccount(Bank bank, string& customerName, string& customerID);
		bool deposit(Bank bank, int year, int month, int day, int accountID, int amount);
		int inquire(Bank bank, int accountID);
		bool withdraw(Bank bank, int year, int month, int day, int accountID, int amount);
		bool transfer(Bank bank, int year, int month, int day, int accountID, int beneficiaryID, int amount);
	private:
		const int m_startCash;
		int m_cash;
		string m_name;
};

