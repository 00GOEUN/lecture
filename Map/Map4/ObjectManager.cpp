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
	//** ���� ���޹��� �Ű������� Ű���� Ȯ���Ѵ�.
	//** ���� ������ Ű���� ���� ���� �ʴ´ٸ� end() �� ��ȯ ��.
	map<string, list<Object*>>::iterator iter = ObjectList.find(_pObject->Getkey());

	//** iter�� ObjectList.end()�� ���ٸ� ������ Ű���� �������� ����.
	//** ���� �������� �ʴ´ٸ�....
	if (iter == ObjectList.end())
	{
		//** map�� ���� ����Ʈ�� ����.
		list<Object*> TempList;

		//** ������ ����Ʈ�� ���޹��� ������Ʈ�� �߰�.
		TempList.push_back(_pObject);

		//** ������Ʈ�� �߰��� ����Ʈ�� ������Ʈ�� Ű������ map�� �߰�. 
		ObjectList.insert(make_pair(_pObject->Getkey(), TempList));
	}

	//** ���� ������ ������ Ű���� ���� �Ѵٸ�....
	else
		//** ������ Ű���� �ִ� ����Ʈ�� �ٷ� �߰����ش�.
		iter->second.push_back(_pObject);
}

void ObjectManager::Render()
{
	//** ��� �ϱ�!!!
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