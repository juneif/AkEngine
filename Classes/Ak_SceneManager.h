#ifndef _AK_SCENEMANAGER_H_
#define _AK_SCENEMANAGER_H_

#include "cocos2d.h"

namespace AK_SCENEMANAGER
{
	enum ETransitionType
	{
		NONE,

		CROSS_FADE,				//cocos2d::TransitionCrossFade
		FADE,					//cocos2d::TransitionFade
		FADE_BL,				//cocos2d::TransitionFadeBL
		FADE_DOWN,				//cocos2d::TransitionFadeDown
		FADE_TR,				//cocos2d::TransitionFadeTR
		FADE_UP,				//cocos2d::TransitionFadeUp
		FLIP_ANGULAR,			//cocos2d::TransitionFlipAngular
		FLIP_X,					//cocos2d::TransitionFlipX
		FLIP_Y,					//cocos2d::TransitionFlipY
		JUMP_ZOOM,				//cocos2d::TransitionJumpZoom
		MOVE_IN_B,				//cocos2d::TransitionMoveInB
		MOVE_IN_L,				//cocos2d::TransitionMoveInL
		MOVE_IN_R,				//cocos2d::TransitionMoveInR
		MOVE_IN_T,				//cocos2d::TransitionMoveInT
		PAGE_TURN,				//cocos2d::TransitionPageTurn
		PROGRESS,				//cocos2d::TransitionProgress
		PROGRESS_HORIZONTAL,	//cocos2d::TransitionProgressHorizontal
		PROGRESS_IN_OUT,		//cocos2d::TransitionProgressInOut
		PROGRESS_OUT_IN,		//cocos2d::TransitionProgressOutIn
		PROGRESS_RADIAL_CCW,	//cocos2d::TransitionProgressRadialCCW
		PROGRESS_RADIAL_CW,		//cocos2d::TransitionProgressRadialCW
		PROGRESS_VERTICAL,		//cocos2d::TransitionProgressVertical
	};

	void Init();
	void Destroy();

	void PushScene();
	void PopScene();
	void ReplaceScene(ETransitionType transition, float time = 1.0f);
	
	cocos2d::Layer* GetObjLayer();
	cocos2d::Layer* GetGUILayer();
}

#endif