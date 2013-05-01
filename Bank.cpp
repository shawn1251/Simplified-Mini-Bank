#include "Bank.h"


Bank::Bank(char name[], Teller& teller)
    : m_startCash(200000), m_cash(m_startCash), m_name(name), teller1(teller)
{

	m_tail = NULL;
	m_head = m_tail;

}


Bank::~Bank(void)
{
}


int Bank::createAccount(string& customerName, string& customerID)
{
    vector<Account*>::iterator iter;
    for (iter=m_accounts.begin(); iter<m_accounts.end(); iter++)
        if ((*iter)->isCustomerID(customerID))
            return 0;

    Account *ptr;
    m_accounts.push_back(ptr=new Account(customerName, customerID));
    return ptr->getAccountID();
}


bool Bank::deposit(int accountID, int amount)
{
    vector<Account*>::iterator iter;
    for (iter=m_accounts.begin(); iter<m_accounts.end(); iter++)
        if ((*iter)->isAccountID(accountID))
        {
            (*iter)->add(amount);
            m_cash += amount;
            MakeNode(2013, 5, 1, accountID, accountID, amount);
            return true;
        }
    return false;
}


int Bank::inquire(int accountID)
{
    vector<Account*>::iterator iter;
    for (iter=m_accounts.begin(); iter<m_accounts.end(); iter++)
        if ((*iter)->isAccountID(accountID))
            return (*iter)->getBalance();
    return -1;
}


bool Bank::withdraw(int accountID, int amount)
{
    vector<Account*>::iterator iter;
    for (iter=m_accounts.begin(); iter<m_accounts.end(); iter++)
        if ((*iter)->isAccountID(accountID))
        {
            if ((*iter)->getBalance() >= amount)
            {
                (*iter)->add(-amount);
                m_cash -= amount;
                MakeNode(2013, 5, 1, accountID, accountID, amount*(-1));
                return true;
            }
            else
                return false;
        }
    return false;
}


bool Bank::transfer(int accountID, int beneficiaryID, int amount)
{
    vector<Account*>::iterator iterFrom, iterTo;
    for (iterFrom=m_accounts.begin(); iterFrom<m_accounts.end(); iterFrom++)
        if ((*iterFrom)->isAccountID(accountID))
            if ((*iterFrom)->getBalance() >= amount)
                break;
            else
                return false;
    if (iterFrom == m_accounts.end())
        return false;
    for (iterTo=m_accounts.begin(); iterTo<m_accounts.end(); iterTo++)
        if ((*iterTo)->isAccountID(beneficiaryID))
            break;
    if (iterTo == m_accounts.end())
        return false;
    (*iterFrom)->add(-amount);
    (*iterTo)->add(amount);
    MakeNode(2013, 5, 1, accountID, beneficiaryID, amount);
    return true;
}


bool Bank::dailyAudit(void)
{
    int total = 0;
    vector<Account*>::iterator iter;
    for (iter=m_accounts.begin(); iter<m_accounts.end(); iter++)
        total += (*iter)->getBalance();
    return m_startCash + total == m_cash;
}

void Bank::MakeNode(int year, int month, int day, int SourceID, int TargetID, int money)
{
	if(m_head == NULL){
		m_head = new TransactionNode(year, month, day, SourceID, TargetID, money);
		m_tail = m_head;
	}

	else{
		TransactionNode* temp;
		temp = m_tail;
		m_tail = new TransactionNode(year, month, day, SourceID, TargetID, money);
		temp->FixNext(m_tail);
	}
}

void Bank::printTransactionList()
{
    TransactionNode* temp;
    temp = m_head;
    temp->PrintNode();
    while(temp != NULL){
        temp->PrintNode();
        temp = temp->GetNext();
    }
}