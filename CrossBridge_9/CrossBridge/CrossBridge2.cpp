#include "stdafx.h"
#include "CrossBridge2.h"


CrossBridge2::CrossBridge2(pair_vec &vec)
{
	m_mem_vec = vec;
	m_n = 2;
	
	if ((signed int)vec.size() < 2)
		throw "Number of team members is wrong!";
}

int CrossBridge2::TimetoTake()
{
	RecordActions(true, m_mem_vec[0], m_mem_vec[1]);
	return m_mem_vec[1].second;
}

