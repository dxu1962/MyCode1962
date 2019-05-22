#pragma once
#include "CrossBridgeBase.h"
class CrossBridge4 :
	public CrossBridgeBase
{
public:
	CrossBridge4(pair_vec &vec);
	int TimetoTake() override;
	~CrossBridge4() = default;
};

