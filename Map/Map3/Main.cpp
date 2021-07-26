#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;


struct Vector3
{
	float x, y, z;

	Vector3() : x(0), y(0), z(0) {}

	Vector3(float _x, float _y) : x(_x), y(_y), z(0) {}

	Vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z) {}
};

struct Transform
{
	Vector3 Position;
	//Vector3 Rotation;
	//Vector3 Scale;
};



//** �߻� Ŭ����
class Object
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
	Object() {}
	virtual ~Object() {}
};



class Player : public Object
{
public:
	virtual void Initialize()override { strKey = "Player"; }
public:
	Player() {}
	virtual ~Player() {}
};

class Enemy : public Object
{
public:
	virtual void Initialize()override { strKey = "Enemy"; }
public:
	Enemy() {}
	virtual ~Enemy() {}
};

class Bullet : public Object
{
public:
	virtual void Initialize()override { strKey = "Bullet"; }
public:
	Bullet() {}
	virtual ~Bullet() {}
};



map<string, list<Object*>> ObjectList;


template <typename T>
Object* CreateObject();

void AddObject(Object* _pObject);



int main(void)
{
	//** ������ �߰�
	Object* pObj = CreateObject<Player>();
	AddObject(pObj);

	//** ������ ���ÿ� �߰�.
	AddObject(CreateObject<Bullet>());
	AddObject(CreateObject<Bullet>());
	AddObject(CreateObject<Bullet>());

	AddObject(CreateObject<Enemy>());
	AddObject(CreateObject<Enemy>());
	AddObject(CreateObject<Enemy>());
	AddObject(CreateObject<Enemy>());


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

	return 0;
}


template <typename T>
Object* CreateObject()
{
	Object* pObj = new T;

	//** Initialize
	pObj->Initialize();

	return pObj;
}


void AddObject(Object* _pObject)
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