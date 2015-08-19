#ifndef __SCENE_H__
#define __SCENE_H__

#include "cocos2d.h"

class Ak_CScene
{
public:
	Ak_CScene();
	~Ak_CScene();

public:
	bool Create();
	void Destroy();

public:
	cocos2d::Scene* GetScene();
	cocos2d::Layer* GetObjLayer();
	cocos2d::Layer* GetGUILayer();

public:
	void Update(float delta);

private:
	bool onTouchesBegan(cocos2d::Touch* pTouch, cocos2d::Event* unused_event);
	void onTouchesMoved(cocos2d::Touch* pTouch, cocos2d::Event* unused_event);
	void onTouchesCancelled(cocos2d::Touch* pTouch, cocos2d::Event* unused_event);
	void onTouchesEnded(cocos2d::Touch* pTouch, cocos2d::Event *unused_event);


private:
	cocos2d::Scene* m_pScene;
	cocos2d::Layer* m_pSceneLayer;

	cocos2d::Layer* m_pObjLayer;
	cocos2d::Layer* m_pGUILayer;
};

#endif