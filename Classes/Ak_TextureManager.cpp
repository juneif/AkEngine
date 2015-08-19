#include "Ak_TextureManager.h"
#include <map>

namespace AK_TEXTUREMANAGER
{
	std::map<std::string, cocos2d::Texture2D*> g_textureMap;

	cocos2d::Texture2D* GetTexture(const char* c_szFileName)
	{
		std::string strFileName = c_szFileName;
		std::map<std::string, cocos2d::Texture2D*>::iterator itor_find = g_textureMap.find(strFileName);
		if (itor_find != g_textureMap.end())
		{
			return itor_find->second;
		}

		std::string strPath = c_szFileName;
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		strPath = "resources/";
		strPath += c_szFileName;
#endif
		cocos2d::Data& rData = cocos2d::FileUtils::getInstance()->getDataFromFile(strPath);
		
		cocos2d::Image* pImage = new cocos2d::Image;
		pImage->initWithImageData(rData.getBytes(), rData.getSize());

		cocos2d::Texture2D* pTexture = new cocos2d::Texture2D;
		pTexture->initWithImage(pImage);
		
		g_textureMap[strFileName] = pTexture;

		pImage->release();

		return pTexture;
	}
}