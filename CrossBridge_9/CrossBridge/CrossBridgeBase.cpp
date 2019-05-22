#include "stdafx.h"
#include "CrossBridgeBase.h"

/*
vec: A vector holding team member's names and time to cross bridge
n: Team members from vec[0] to vec [n-1]
*/
CrossBridgeBase::CrossBridgeBase()
{
}

void CrossBridgeBase::DisplayMembers()
{
	int n = 0;
	for (auto const &p : m_mem_vec)
	{
		cout << '{' << p.first << "," << p.second << '}' << '\n';
		//n++;
		//if (n > m_n)
		//	break;
	}
}

void CrossBridgeBase::DisplayActions()
{
	for (auto const &act : m_act_vec)
	{
		cout << act << '\n';
	}
}

//direction: cross forward (true); reture (false)
void CrossBridgeBase::RecordActions(bool direction, pair<string, int> p1, pair<string, int> p2)
{

	string str = string();
	if (direction)
		str = "Cross forward: ";
	else
		str = "Return: ";
	str += p1.first;
	str += " and ";
	str += p2.first;

	m_act_vec.push_back(str);
}

void CrossBridgeBase::RecordActions(bool direction, pair<string, int> p1)
{

	string str = string();
	if (direction)
		str = "Cross forward: ";
	else
		str = "Return: ";
	str += p1.first;
	m_act_vec.push_back(str);
}
