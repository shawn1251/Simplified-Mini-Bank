#pragma once

#include <string>
#include <vector>
using namespace std;

#include "Account.h"
#include "TransactionNode.h"
#include "Teller.h"

class Bank
{
public:
    Bank(char name[], Teller& teller);
    virtual ~Bank(void);
    int createAccount(string& customerName, string& customerID);
    bool deposit(int accountID, int amount);
    int inquire(int accountID);
    bool withdraw(int accountID, int amount);
    bool transfer(int accountID, int beneficiaryID, int amount);
    bool dailyAudit(void);
	void MakeNode(int year, int month, int day, int SourceID, int TargetID, int money);
    void printTransactionList();
private:
	Teller teller1;
	// Teller teller2;
    vector<Account *> m_accounts;
    const int m_startCash;
    int m_cash;
    string m_name;
	TransactionNode* m_head;
	TransactionNode* m_tail;

};

