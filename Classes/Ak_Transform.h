#ifndef _AK_TRANSFORM_H_
#define _AK_TRANSFORM_H_

class Ak_CTransform
{
public:
	Ak_CTransform();
	virtual ~Ak_CTransform();

public:
	void UpdateTransform();

public:
	void SetPositionX(float posX);
	void SetPositionY(float posY);
	void SetScaleX(float scaleX);
	void SetScaleY(float scaleY);
	void SetRotation(float rotation);

public:
	float GetPositionX();
	float GetPositionY();
	float GetScaleX();
	float GetScaleY();
	float GetRotation();

protected:
	virtual void OnModifyTransform();

protected:
	bool m_isModifyTransform;

protected:
	float m_posX;
	float m_posY;
	float m_scaleX;
	float m_scaleY;
	float m_rotation;

};

#endif