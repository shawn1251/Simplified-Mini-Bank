#pragma once
#include <string>
#include <vector>
using namespace std;

class TransactionNode
{
	public:
		TransactionNode(int year, int month, int day, int SourceID, int TargetID, int money);
		virtual ~TransactionNode(void);
		void FixNext(TransactionNode* next);
	private:
		int m_year;
		int m_month;
		int m_day;
		int m_SourceID;
		int m_TargetID;
		int m_money;
		TransactionNode* m_next;
};
