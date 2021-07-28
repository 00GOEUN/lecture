#pragma once
#include "Object1.h"

template <typename T>
class ObjectFactory
{
public:
	static Object1* CreateObject()
	{
		Object1* pObj = new T;

		pObj->Initialize();

		return pObj;
	}
};