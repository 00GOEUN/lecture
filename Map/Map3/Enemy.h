#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	virtual void Initialize()override { strKey = "Bullet"; }
public:
	Enemy() {}
	virtual ~Enemy() {}

};