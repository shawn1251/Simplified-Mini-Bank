#include "TransactionNode.h"

TransactionNode::TransactionNode(int year, int month, int day, int SourceID, int TargetID, int money)
{
	m_year = year;
	m_month = month;
	m_day = day;
	m_SourceID = SourceID;
	m_TargetID = TargetID;
	m_money = money;
	m_next = NULL;
}
TransactionNode::~TransactionNode(void)
{
}
void TransactionNode::FixNext(TransactionNode* next)
{
	m_next = next;
}