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



//** 추상 클레스
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
	//** 생성후 추가
	Object* pObj = CreateObject<Player>();
	AddObject(pObj);

	//** 생성과 동시에 추가.
	AddObject(CreateObject<Bullet>());
	AddObject(CreateObject<Bullet>());
	AddObject(CreateObject<Bullet>());

	AddObject(CreateObject<Enemy>());
	AddObject(CreateObject<Enemy>());
	AddObject(CreateObject<Enemy>());
	AddObject(CreateObject<Enemy>());


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