#pragma once
#include "Object1.h"

class Bullet1 : public Object1
{
public:
	virtual void Initialize()override { strKey = "Bullet"; }
public:
	Bullet1() {}
	virtual ~Bullet1() {}

};

