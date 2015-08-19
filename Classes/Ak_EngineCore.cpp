#include "Ak_EngineCore.h"
#include "Ak_LuaGlue.h"
#include "Ak_SceneManager.h"

Ak_CEngineCore::Ak_CEngineCore()
{
}

Ak_CEngineCore::~Ak_CEngineCore()
{
}

void Ak_CEngineCore::Init()
{
	LuaGlue_Init();

	AK_SCENEMANAGER::Init();
}

void Ak_CEngineCore::Update(float delta)
{
}

void Ak_CEngineCore::Destroy()
{
}