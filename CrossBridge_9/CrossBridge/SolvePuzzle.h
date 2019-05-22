#pragma once
#include<vector>
#include <string>
#include <iostream>
#include <memory>
#include <algorithm>
#include "stdio.h"
#include <map>
#include <fstream>
#include <sstream>
#include "CrossBridgeBase.h"
#include "CrossBridgeN.h"
#include "CrossBridgeN2.h"

class SolvePuzzle
{
public:
	SolvePuzzle();
	pair_vec ReadYAMLFile(string filepath);
	int Solve(string filePath);
	int Solve2(string filePath);
	~SolvePuzzle();

	int GetMinTime() { return m_MinTime; }
	void DisplayMembers() { pCB->DisplayMembers(); }
	void DisplayActions() { pCB->DisplayActions(); }
private:
	CrossBridgeBase *pCB;
	CrossBridgeBase *pCB2;
	int m_MinTime;
};

