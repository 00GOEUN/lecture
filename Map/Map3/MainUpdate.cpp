#include "MainUpdate.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

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