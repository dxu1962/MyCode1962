#include "stdafx.h"
#include "CrossBridgeN2.h"
#include "CrossBridge1.h"
#include "CrossBridge2.h"
#include "CrossBridge3.h"
#include "CrossBridge4.h"

CrossBridgeN2::CrossBridgeN2(pair_vec &vec, int n)
{
	m_mem_vec = vec;
	m_n = n;

	if (n > (signed int)vec.size())
		throw "Number of team members is wrong!";
}

int CrossBridgeN2::TimetoTake()
{
	if (m_n == 0)
		return 0;

	int minTime = 0;
	int n_ToCross = m_n;
	CrossBridgeBase *pCB = nullptr;
	while (true)
	{	
		if (n_ToCross == 1)
		{
			pCB = new CrossBridge1(m_mem_vec);
			minTime += pCB->TimetoTake();
			delete pCB;
			return minTime;
		}
		if (n_ToCross == 2)
		{
			pCB = new CrossBridge2(m_mem_vec);
			minTime += pCB->TimetoTake();
			delete pCB;
			return minTime;
		}
		if (n_ToCross == 3)
		{
			pCB = new CrossBridge3(m_mem_vec);
			minTime += pCB->TimetoTake();
			delete pCB;
			return minTime;
		}
		if (n_ToCross == 4)
		{
			pCB = new CrossBridge4(m_mem_vec);
			pCB->SetFiveSteps(false);
			minTime += pCB->TimetoTake();
			delete pCB;
			return minTime;
		}

		//n_ToCross > 4
		pair_vec temp_vec;
		temp_vec.push_back(m_mem_vec[0]);
		temp_vec.push_back(m_mem_vec[1]);
		temp_vec.push_back(m_mem_vec[n_ToCross - 2]);
		temp_vec.push_back(m_mem_vec[n_ToCross - 1]);

		pCB = new CrossBridge4(temp_vec);
		pCB->SetFiveSteps(true);
		minTime += pCB->TimetoTake();
		delete pCB;

		n_ToCross -= 2;
	}
}
