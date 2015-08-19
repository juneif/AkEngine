#ifndef _AK_ENGINECORE_H_
#define _AK_ENGINECORE_H_

class Ak_CEngineCore
{
public:
	Ak_CEngineCore();
	virtual ~Ak_CEngineCore();

public:
	void Init();
	void Update(float delta);
	void Destroy();
};

#endif