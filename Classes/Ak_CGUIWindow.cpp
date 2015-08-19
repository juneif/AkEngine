#include "Ak_CGUIWindow.h"
#include "Ak_TextureManager.h"
#include "Ak_SceneManager.h"

Ak_CGUIWindow::Ak_CGUIWindow()
: m_pLayer(NULL)
, m_pColorLayerIn(NULL)
, m_pColorLayerOut(NULL)
, m_pSprite(NULL)
, m_id(0)
, m_pParent(NULL)
, m_width(100.0f)
, m_height(100.0f)
, m_red(255)
, m_green(255)
, m_blue(255)
, m_opacity(255)
, m_isRefreshWindow(false)
{
}

Ak_CGUIWindow::~Ak_CGUIWindow()
{
}

void Ak_CGUIWindow::Create(unsigned int id, bool isRootWindow)
{
	m_id = id;

	m_pLayer = cocos2d::Layer::create();
	m_pLayer->setPosition(m_posX, m_posY);
	m_pLayer->setContentSize(cocos2d::Size(m_width, m_height));
	

	m_pColorLayerOut = cocos2d::LayerColor::create(cocos2d::Color4B(255, 255, 255, 255), m_width, m_height);
	m_pColorLayerOut->setPosition(0, 0);
	m_pLayer->addChild(m_pColorLayerOut);

	m_pColorLayerIn = cocos2d::LayerColor::create(cocos2d::Color4B(0, 0, 0, 255), m_width - 2, m_height - 2);
	m_pColorLayerIn->setPosition(1, 1);
	m_pColorLayerOut->addChild(m_pColorLayerIn);

	m_isRootWindow = isRootWindow;

	if (isRootWindow)
		AK_SCENEMANAGER::GetGUILayer()->addChild(m_pLayer);
}

void Ak_CGUIWindow::Update(float delta)
{
	UpdateTransform();

	if (m_isRefreshWindow)
	{
		OnRefreshWindow();
		m_isRefreshWindow = false;
	}
}

void Ak_CGUIWindow::Destroy()
{
	std::list<Ak_CGUIWindow*>::iterator itor = m_childList.begin();
	std::list<Ak_CGUIWindow*>::iterator itor_end = m_childList.end();
	for (; itor != itor_end; itor++)
	{
		Ak_CGUIWindow* pChild = *itor;
		pChild->Destroy();
		delete pChild;
	}
	m_childList.empty();

	if (m_pParent)
		m_pParent->RemoveChild(this);
}

unsigned int Ak_CGUIWindow::GetID()
{
	return m_id;
}

cocos2d::Layer* Ak_CGUIWindow::GetLayer()
{
	return m_pLayer;
}

void Ak_CGUIWindow::SetParent(Ak_CGUIWindow* pParent)
{
	if (m_isRootWindow)
		return;

	m_pParent = pParent;
}

void Ak_CGUIWindow::AddChild(Ak_CGUIWindow* pWindow)
{
	std::list<Ak_CGUIWindow*>::iterator itor = m_childList.begin();
	std::list<Ak_CGUIWindow*>::iterator itor_end = m_childList.end();
	for (; itor != itor_end; itor++)
	{
		Ak_CGUIWindow* pChild = *itor;
		if (pChild->GetID() == pWindow->GetID())
			return;
	}

	cocos2d::Layer* pLayer = pWindow->GetLayer();
	if (!pLayer)
		return;

	m_pLayer->addChild(pLayer);
	pWindow->SetParent(this);

	m_childList.push_back(pWindow);
}

void Ak_CGUIWindow::RemoveChild(Ak_CGUIWindow* pWindow)
{
	std::list<Ak_CGUIWindow*>::iterator itor = m_childList.begin();
	std::list<Ak_CGUIWindow*>::iterator itor_end = m_childList.end();
	for (; itor != itor_end; itor++)
	{
		Ak_CGUIWindow* pChild = *itor;
		if (pChild->GetID() != pWindow->GetID())
			continue;

		m_pLayer->removeChild(pWindow->GetLayer(), false);
		pWindow->SetParent(NULL);
		m_childList.erase(itor);
		break;
	}
}

void Ak_CGUIWindow::SetColor(unsigned char r, unsigned char g, unsigned char b, unsigned char opacity)
{
	m_red = r;
	m_green = g;
	m_blue = b;
	m_opacity = opacity;

	m_isRefreshWindow = true;
}

void Ak_CGUIWindow::SetTexture(const char* c_szFileName)
{
	cocos2d::Texture2D* pTexture = AK_TEXTUREMANAGER::GetTexture(c_szFileName);
	if (!pTexture)
		return;

	if (m_pSprite)
	{
		m_pSprite->setTexture(pTexture);
	}
	else
	{
		m_pSprite = cocos2d::Sprite::createWithTexture(pTexture);
		m_pLayer->addChild(m_pSprite);
	}

	m_pColorLayerIn->setVisible(false);
	m_pColorLayerOut->setVisible(false);

	m_isRefreshWindow = true;
}

void Ak_CGUIWindow::SetWidth(float width)
{
	m_width = width;
	m_isRefreshWindow = true;
}

void Ak_CGUIWindow::SetHeight(float height)
{
	m_height = height;
	m_isRefreshWindow = true;
}

float Ak_CGUIWindow::GetWidth()
{
	return m_width;
}

float Ak_CGUIWindow::GetHeight()
{
	return m_height;
}

void Ak_CGUIWindow::OnModifyTransform()
{
	OnRefreshWindow();
}

void Ak_CGUIWindow::OnRefreshWindow()
{
	m_pLayer->setPosition(m_posX, m_posY);
	m_pLayer->setContentSize(cocos2d::Size(m_width, m_height));
	m_pLayer->setScaleX(m_scaleX);
	m_pLayer->setScaleY(m_scaleY);
	m_pLayer->setRotation(m_rotation);

	if (m_pSprite)
	{
		RefreshSprite();
	}
	else
	{
		RefreshDefaultOutline();
	}
	
}

void Ak_CGUIWindow::RefreshSprite()
{
	if (!m_pSprite)
		return;

	float posX = m_width / 2;
	float posY = m_height / 2;
	m_pSprite->setPosition(posX, posY);

	m_pSprite->setColor(cocos2d::Color3B(m_red, m_green, m_blue));
	m_pSprite->setOpacity(m_opacity);
}

void Ak_CGUIWindow::RefreshDefaultOutline()
{
	m_pColorLayerOut->setContentSize(cocos2d::Size(m_width, m_height));
	m_pColorLayerIn->setContentSize(cocos2d::Size(m_width - 2, m_height - 2));

	m_pColorLayerIn->setColor(cocos2d::Color3B(m_red, m_green, m_blue));
	m_pColorLayerIn->setOpacity(m_opacity);
}