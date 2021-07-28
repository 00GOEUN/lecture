#pragma once
#include "Headers.h"

class Object1
{
protected:
	Transform Info;
	string strKey;
public:
	virtual void Initialize() = 0;
public:
	void Output() { cout << strKey << endl; }
	string Getkey() { return strKey; }
public:
	Object1() {}
	virtual ~Object1() {}
};

