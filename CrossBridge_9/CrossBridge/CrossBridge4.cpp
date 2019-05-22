#include "stdafx.h"
#include "CrossBridge4.h"


CrossBridge4::CrossBridge4(pair_vec &vec)
{
	m_mem_vec = vec;
	m_n = 4;
	
	if ((signed int)vec.size() < 1)
		throw "Number of team members is wrong!";
}

int CrossBridge4::TimetoTake()
{
	int n = m_n;
	bool case1 = 2 * m_mem_vec[1].second > m_mem_vec[0].second + m_mem_vec[n - 2].second;
	int Smaller = case1 ? m_mem_vec[0].second + m_mem_vec[n - 2].second : 2 * m_mem_vec[1].second;
	if (case1)
	{
		RecordActions(true, m_mem_vec[0], m_mem_vec[1]);
		RecordActions(false, m_mem_vec[0]);
		RecordActions(true, m_mem_vec[n - 2], m_mem_vec[n - 1]);
		RecordActions(false, m_mem_vec[1]);
	}
	else
	{
		RecordActions(true, m_mem_vec[0], m_mem_vec[n - 1]);
		RecordActions(false, m_mem_vec[0]);
		RecordActions(true, m_mem_vec[0], m_mem_vec[n - 2]);
		RecordActions(false, m_mem_vec[1]);
	}
	if (!m_five_steps)
	{
		RecordActions(true, m_mem_vec[0], m_mem_vec[1]);
		return m_mem_vec[0].second + m_mem_vec[n - 1].second + Smaller + m_mem_vec[1].second;
	}
	else
	{
		return m_mem_vec[0].second + m_mem_vec[n - 1].second + Smaller;
	}
}

