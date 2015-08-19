#include "Ak_InputManager.h"


#include "Ak_SceneManager.h"
#include "Ak_TextureManager.h"
#include "Ak_CGUIWindow.h"
int g_tempCount = 0;
Ak_CGUIWindow window;
Ak_CGUIWindow win2;

namespace AK_INPUTMANAGER
{
	void OnTouchBegin(float x, float y)
	{
		g_tempCount++;
		printf("tempCount = %d\n", g_tempCount);

		if (1 == g_tempCount)
		{
			cocos2d::Layer* pLayer = AK_SCENEMANAGER::GetGUILayer();

			window.Create(1, true);
			window.SetPositionX(20);
			window.SetPositionY(20);
			window.SetWidth(500);
			window.SetHeight(500);
			window.SetColor(255, 0, 0, 255);

			win2.Create(2);
			window.AddChild(&win2);
			win2.SetPositionX(50);
			win2.SetPositionY(50);
			win2.SetWidth(200);
			win2.SetHeight(200);
			win2.SetTexture("a.png");
		}
		else if (2 == g_tempCount)
		{
			window.SetColor(0, 255, 0, 255);
			win2.SetColor(255, 0, 0, 255);
		}
		else if (3 == g_tempCount)
		{
			window.SetColor(0, 0, 255, 255);
			win2.SetColor(255, 255, 255, 128);
		}

		win2.SetRotation(10 * g_tempCount);

		window.Update(16);
		win2.Update(16);

	}

	void OnTouchMove(float x, float y)
	{
	}

	void OnTouchEnd(float x, float y)
	{
	}
}