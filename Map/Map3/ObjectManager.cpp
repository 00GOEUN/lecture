#include "ObjectManager.h"
#include "Object.h"

ObjectManager* ObjectManager::Instance = NULL;


ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{
	Release();
}


void ObjectManager::AddObject(Object* _pObject)
{
	//** 지금 전달받은 매개변수의 키값을 확인한다.
	//** 만약 기존에 키값이 존재 하지 않는다면 end() 를 반환 함.
	map<string, list<Object*>>::iterator iter = ObjectList.find(_pObject->Getkey());

	//** iter가 ObjectList.end()와 같다면 기존에 키값이 존재하지 않음.
	//** 만약 존재하지 않는다면....
	if (iter == ObjectList.end())
	{
		//** map에 넣을 리스트를 생성.
		list<Object*> TempList;

		//** 생성한 리스트에 전달받은 오브젝트를 추가.
		TempList.push_back(_pObject);

		//** 오브젝트를 추가한 리스트를 오브젝트의 키값으로 map에 추가. 
		ObjectList.insert(make_pair(_pObject->Getkey(), TempList));
	}

	//** 만약 기존에 동일한 키값이 존재 한다면....
	else
		//** 동일한 키값에 있는 리스트에 바로 추가해준다.
		iter->second.push_back(_pObject);
}

void ObjectManager::Render()
{
	//** 출력 하기!!!
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = (*iter).second.begin();
			iter2 != (*iter).second.end(); ++iter2)
		{
			(*iter2)->Output();
		}
	}
}

void ObjectManager::Release()
{
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = (*iter).second.begin();
			iter2 != (*iter).second.end(); ++iter2)
		{
			delete (*iter2);
			(*iter2) = NULL;
		}
		(*iter).second.clear();
	}
	ObjectList.clear();
}