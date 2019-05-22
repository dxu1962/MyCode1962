#include "stdafx.h"
#include "CrossBridge3.h"


CrossBridge3::CrossBridge3(pair_vec &vec)
{
	m_mem_vec = vec;
	m_n = 3;
	
	if ((signed int)vec.size() < 1)
		throw "Number of team members is wrong!";
}

int CrossBridge3::TimetoTake()
{
	RecordActions(true, m_mem_vec[0], m_mem_vec[2]);
	RecordActions(false, m_mem_vec[0]);
	RecordActions(true, m_mem_vec[0], m_mem_vec[1]);
	return m_mem_vec[0].second + m_mem_vec[1].second + m_mem_vec[2].second;
}
