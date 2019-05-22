#pragma once
#include "CrossBridgeBase.h"
class CrossBridge3 :
	public CrossBridgeBase
{
public:
	CrossBridge3(pair_vec &vec);
	int TimetoTake() override;
	~CrossBridge3() = default;
};

