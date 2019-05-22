#include "stdafx.h"
#include "CrossBridgeN.h"

//Calculate total time with a recursive function with N>0 members
CrossBridgeN::CrossBridgeN(pair_vec &vec, int n)
{
	m_mem_vec = vec;
	m_n = n;
	
	if (n > (signed int)vec.size())
		throw "Number of team members is wrong!";
}

int CrossBridgeN::TimetoTake()
{
	if (m_n == 0)
		return 0;
	if (m_n < 3)
	{
		if (m_n == 1)
			RecordActions(true, m_mem_vec[0]);
		if (m_n == 2)
			RecordActions(true, m_mem_vec[0], m_mem_vec[1]);
		return m_mem_vec[m_n - 1].second;
	}
	else if (m_n == 3)
	{
		RecordActions(true, m_mem_vec[0], m_mem_vec[2]);
		RecordActions(false, m_mem_vec[0]);
		RecordActions(true, m_mem_vec[0], m_mem_vec[1]);
		return m_mem_vec[0].second + m_mem_vec[1].second + m_mem_vec[2].second;
	}
	else
	{
		int n = m_n;
		bool case2 = 2 * m_mem_vec[1].second > m_mem_vec[0].second + m_mem_vec[n - 2].second;
		int Smaller = min( m_mem_vec[0].second + m_mem_vec[n - 2].second , 2 * m_mem_vec[1].second);

		if (!case2)
		{
			RecordActions(true, m_mem_vec[0], m_mem_vec[1]);
			RecordActions(false, m_mem_vec[0]);
			RecordActions(true, m_mem_vec[n-2], m_mem_vec[n-1]);
			RecordActions(false, m_mem_vec[1]);
		}
		else
		{
			RecordActions(true, m_mem_vec[0], m_mem_vec[n-1]);
			RecordActions(false, m_mem_vec[0]);
			RecordActions(true, m_mem_vec[0], m_mem_vec[n - 2]);
			RecordActions(false, m_mem_vec[0]);
		}

		m_n -= 2;
		return m_mem_vec[0].second + m_mem_vec[n - 1].second + Smaller + TimetoTake();
	}
}

