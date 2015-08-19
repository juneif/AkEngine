#include "Ak_SceneManager.h"
#include "cocos2d.h"
#include <list>

#include "Ak_Scene.h"

namespace AK_SCENEMANAGER
{	
	std::list<Ak_CScene*> g_sceneList;

	void Init()
	{
		Ak_CScene* pScene = new Ak_CScene;
		pScene->Create();
		g_sceneList.push_back(pScene);

		cocos2d::Director::getInstance()->runWithScene(pScene->GetScene());
	}

	void Destroy()
	{
	}

	void PushScene()
	{
		Ak_CScene* pScene = new Ak_CScene;
		pScene->Create();
		g_sceneList.push_back(pScene);

		cocos2d::Director::getInstance()->pushScene(pScene->GetScene());
	}

	void PopScene()
	{
		cocos2d::Director::getInstance()->popScene();

		Ak_CScene* pScene = *(g_sceneList.rbegin());
		pScene->Destroy();
		delete pScene;
		g_sceneList.pop_back();
	}

	void ReplaceScene(ETransitionType transition, float time)
	{
		Ak_CScene* pNewScene = new Ak_CScene;
		pNewScene->Create();

		cocos2d::Scene *pReplaceScene = NULL;
		if (NONE == transition)
		{
			pReplaceScene = pNewScene->GetScene();
		}
		else if (CROSS_FADE == transition)
		{
			pReplaceScene = cocos2d::TransitionCrossFade::create(time, pNewScene->GetScene());
		}
		else if (FADE == transition)
		{
			pReplaceScene = cocos2d::TransitionFade::create(time, pNewScene->GetScene());
		}
		else if (FADE_BL == transition)
		{
			pReplaceScene = cocos2d::TransitionFadeBL::create(time, pNewScene->GetScene());
		}
		else if (FADE_DOWN == transition)
		{
		}
		else if (FADE_TR == transition)
		{
		}
		else if (FADE_UP == transition)
		{
		}
		else if (FLIP_ANGULAR == transition)
		{
		}
		else if (FLIP_X == transition)
		{
		}
		else if (FLIP_Y == transition)
		{
		}
		else if (JUMP_ZOOM == transition)
		{
		}
		else if (MOVE_IN_B == transition)
		{
		}
		else if (MOVE_IN_L == transition)
		{
		}
		else if (MOVE_IN_R == transition)
		{
		}
		else if (MOVE_IN_T == transition)
		{
		}
		else if (PAGE_TURN == transition)
		{
		}
		else if (PROGRESS == transition)
		{
		}
		else if (PROGRESS_HORIZONTAL == transition)
		{
		}
		else if (PROGRESS_IN_OUT == transition)
		{
		}
		else if (PROGRESS_OUT_IN == transition)
		{
		}
		else if (PROGRESS_RADIAL_CCW == transition)
		{
		}
		else if (PROGRESS_RADIAL_CW == transition)
		{
		}
		else if (PROGRESS_VERTICAL == transition)
		{
		}

		cocos2d::Director::getInstance()->replaceScene(pReplaceScene);

		Ak_CScene* pOldScene = *(g_sceneList.rbegin());
		pOldScene->Destroy();
		delete pOldScene;
		g_sceneList.pop_back();
		g_sceneList.push_back(pNewScene);

	}

	cocos2d::Layer* GetObjLayer()
	{
		Ak_CScene* pCurScene = *(g_sceneList.rbegin());
		if (!pCurScene)
			return NULL;

		return pCurScene->GetObjLayer();
	}

	cocos2d::Layer* GetGUILayer()
	{
		Ak_CScene* pCurScene = *(g_sceneList.rbegin());
		if (!pCurScene)
			return NULL;

		return pCurScene->GetGUILayer();
	}

}