#include "Ak_Scene.h"
#include "Ak_InputManager.h"
#include "Ak_EngineCore.h"

extern Ak_CEngineCore* g_pEngine;


Ak_CScene::Ak_CScene()
: m_pScene(NULL)
, m_pSceneLayer(NULL)
, m_pObjLayer(NULL)
, m_pGUILayer(NULL)
{
}

Ak_CScene::~Ak_CScene()
{
}

bool Ak_CScene::Create()
{
	m_pScene = cocos2d::Scene::create();
	m_pScene->schedule(cocos2d::SEL_SCHEDULE(&Ak_CScene::Update), 1 / 60);
	
	m_pSceneLayer = cocos2d::Layer::create();
	m_pSceneLayer->setTouchEnabled(true);
	m_pScene->addChild(m_pSceneLayer);

	m_pObjLayer = cocos2d::Layer::create();
	m_pSceneLayer->addChild(m_pObjLayer);

	m_pGUILayer = cocos2d::Layer::create();
	m_pSceneLayer->addChild(m_pGUILayer);

	cocos2d::EventListenerTouchOneByOne* listener = cocos2d::EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(Ak_CScene::onTouchesBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Ak_CScene::onTouchesMoved, this);
	listener->onTouchCancelled = CC_CALLBACK_2(Ak_CScene::onTouchesCancelled, this);
	listener->onTouchEnded = CC_CALLBACK_2(Ak_CScene::onTouchesEnded, this);


	cocos2d::EventDispatcher* pEventDispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
	pEventDispatcher->addEventListenerWithFixedPriority(listener, 1);

	return true;
}

void Ak_CScene::Destroy()
{

}

cocos2d::Scene* Ak_CScene::GetScene()
{
	return m_pScene;
}

cocos2d::Layer* Ak_CScene::GetObjLayer()
{
	return m_pObjLayer;
}

void Ak_CScene::Update(float delta)
{
	g_pEngine->Update(delta);
}

cocos2d::Layer* Ak_CScene::GetGUILayer()
{
	return m_pGUILayer;
}

bool Ak_CScene::onTouchesBegan(cocos2d::Touch* pTouch, cocos2d::Event* unused_event)
{
	float posX = pTouch->getLocation().x;
	float posY = pTouch->getLocation().y;

	AK_INPUTMANAGER::OnTouchBegin(posX, posY);

	return true;
}

void Ak_CScene::onTouchesMoved(cocos2d::Touch* pTouch, cocos2d::Event* unused_event)
{
	float posX = pTouch->getLocation().x;
	float posY = pTouch->getLocation().y;

	AK_INPUTMANAGER::OnTouchMove(posX, posY);
}

void Ak_CScene::onTouchesCancelled(cocos2d::Touch* pTouch, cocos2d::Event* unused_event)
{
	printf("OnTouchCancelled\n");
}

void Ak_CScene::onTouchesEnded(cocos2d::Touch* pTouch, cocos2d::Event *unused_event)
{
	float posX = pTouch->getLocation().x;
	float posY = pTouch->getLocation().y;

	AK_INPUTMANAGER::OnTouchEnd(posX, posY);
}