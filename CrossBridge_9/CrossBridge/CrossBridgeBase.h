#pragma once
#include<vector>
#include <string>
#include <iostream>
#include <memory>
#include <algorithm>
#include "stdio.h"
#include <map>

using namespace std;
typedef vector<pair<string, int>> pair_vec;

class CrossBridgeBase
{
public:
	CrossBridgeBase();
	virtual int TimetoTake() = 0;
	virtual ~CrossBridgeBase() = default;
	void DisplayMembers();
	void DisplayActions();

	//If 5 steps will leave slowest two people on the left side of bridge (Only for CrossBridge4
	void SetFiveSteps(bool five_steps) { m_five_steps = five_steps; }
protected:
	void RecordActions(bool direction, pair<string, int> p1, pair<string, int> p2);
	void RecordActions(bool direction, pair<string, int> p1);
	pair_vec m_mem_vec;
	int m_n;
	vector<string> m_act_vec;
	bool m_five_steps;
};

