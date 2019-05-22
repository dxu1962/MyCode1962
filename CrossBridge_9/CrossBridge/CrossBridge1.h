#pragma once
#include "CrossBridgeBase.h"
class CrossBridge1 :
	public CrossBridgeBase
{
public:
	CrossBridge1(pair_vec &vec);
	int TimetoTake() override;
	~CrossBridge1()=default;
};

