#pragma once
#include "CrossBridgeBase.h"
class CrossBridgeN :
	public CrossBridgeBase
{
public:
	CrossBridgeN(pair_vec &vec, int n);
	int TimetoTake() override;
	~CrossBridgeN() = default;
};

