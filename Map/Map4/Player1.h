#pragma once
#include "Object1.h"

class Player1 : public Object1
{
public:
	virtual void Initialize()override { strKey = "Bullet"; }
public:
	Player1() {}
	virtual ~Player1() {}

};