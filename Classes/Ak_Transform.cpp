#include "Ak_Transform.h"

Ak_CTransform::Ak_CTransform()
: m_posX(0.0f)
, m_posY(0.0f)
, m_scaleX(1.0f)
, m_scaleY(1.0f)
, m_rotation(0.0f)
, m_isModifyTransform(false)
{
}

Ak_CTransform::~Ak_CTransform()
{
}

void Ak_CTransform::UpdateTransform()
{
	if (!m_isModifyTransform)
		return;

	OnModifyTransform();

	m_isModifyTransform = false;
}

void Ak_CTransform::SetPositionX(float posX)
{
	m_posX = posX;
	m_isModifyTransform = true;
}

void Ak_CTransform::SetPositionY(float posY)
{
	m_posY = posY;
	m_isModifyTransform = true;
}

void Ak_CTransform::SetScaleX(float scaleX)
{
	m_scaleX = scaleX;
	m_isModifyTransform = true;
}

void Ak_CTransform::SetScaleY(float scaleY)
{
	m_scaleY = scaleY;
	m_isModifyTransform = true;
}

void Ak_CTransform::SetRotation(float rotation)
{
	m_rotation = rotation;
	m_isModifyTransform = true;
}

float Ak_CTransform::GetPositionX()
{
	return m_posX;
}

float Ak_CTransform::GetPositionY()
{
	return m_posY;
}

float Ak_CTransform::GetScaleX()
{
	return m_scaleX;
}

float Ak_CTransform::GetScaleY()
{
	return m_scaleY;
}

float Ak_CTransform::GetRotation()
{
	return m_rotation;
}

void Ak_CTransform::OnModifyTransform()
{
}