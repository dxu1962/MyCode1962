#include "stdafx.h"
#include "CrossBridge1.h"

CrossBridge1::CrossBridge1(pair_vec &vec)
{
	m_mem_vec = vec;
	m_n = 1;
	
	if (vec.size() < 1)
		throw "Number of team members is wrong!";
}

int CrossBridge1::TimetoTake()
{
	RecordActions(true, m_mem_vec[0]);
	return m_mem_vec[0].second;
}

