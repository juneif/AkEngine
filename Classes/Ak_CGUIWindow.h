#ifndef _AK_CGUIWINDOW_H_
#define _AK_CGUIWINDOW_H_

#include "cocos2d.h"
#include "Ak_Transform.h"

class Ak_CGUIWindow : public Ak_CTransform
{
public:
	Ak_CGUIWindow();
	virtual ~Ak_CGUIWindow();

public:
	void Create(unsigned int id, bool isRootWindow = false);
	void Update(float delta);
	void Destroy();

public:
	unsigned int GetID();
	cocos2d::Layer* GetLayer();

public:
	void SetParent(Ak_CGUIWindow* pParent);
	void AddChild(Ak_CGUIWindow* pWindow);
	void RemoveChild(Ak_CGUIWindow* pWindow);

public:
	void SetColor(unsigned char r, unsigned char g, unsigned char b, unsigned char opacity);

public:
	void SetTexture(const char* c_szFileName);

public:
	void SetWidth(float width);
	void SetHeight(float height);

public:
	float GetWidth();
	float GetHeight();

protected:
	virtual void OnModifyTransform();
	virtual void OnRefreshWindow();

private:
	void RefreshSprite();
	void RefreshDefaultOutline();

private:
	float m_width;
	float m_height;

	unsigned char m_red;
	unsigned char m_green;
	unsigned char m_blue;
	unsigned char m_opacity;

	bool m_isRefreshWindow;

private:
	bool m_isRootWindow;
	Ak_CGUIWindow* m_pParent;
	std::list<Ak_CGUIWindow*> m_childList;

private:
	unsigned int m_id;

private:
	cocos2d::Layer* m_pLayer;
	cocos2d::LayerColor* m_pColorLayerIn;
	cocos2d::LayerColor* m_pColorLayerOut;
	cocos2d::Sprite* m_pSprite;
};

#endif