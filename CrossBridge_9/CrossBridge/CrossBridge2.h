#pragma once
#include "CrossBridgeBase.h"
class CrossBridge2 :
	public CrossBridgeBase
{
public:
	CrossBridge2(pair_vec &vec);
	int TimetoTake() override;
	~CrossBridge2()=default;
};

