#pragma once
#include "Object1.h"

class Enemy1 : public Object1
{
public:
	virtual void Initialize()override { strKey = "Bullet"; }
public:
	Enemy1() {}
	virtual ~Enemy1() {}

};
