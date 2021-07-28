#include "MainUpdate.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"

#include "Player1.h"
#include "Bullet1.h"
#include "Enemy1.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	Release();
}


void MainUpdate::Initialzie()
{
	Object* pObj = ObjectFactory<Player>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pObj);


	for (int i = 0; i < 3; ++i)
		ObjectManager::GetInstance()->AddObject(
			ObjectFactory<Bullet>::CreateObject());

	for (int i = 0; i < 4; ++i)
		ObjectManager::GetInstance()->AddObject(
			ObjectFactory<Enemy>::CreateObject());
}

void MainUpdate::Update()
{

}

void MainUpdate::Render()
{
	ObjectManager::GetInstance()->Render();
}

void MainUpdate::Release()
{

}