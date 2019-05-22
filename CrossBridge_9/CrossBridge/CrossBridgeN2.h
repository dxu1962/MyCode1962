#pragma once
#include "CrossBridgeBase.h"
class CrossBridgeN2 :
	public CrossBridgeBase
{
public:
	CrossBridgeN2(pair_vec &vec, int n);
	int TimetoTake() override;
	~CrossBridgeN2() = default;
};



