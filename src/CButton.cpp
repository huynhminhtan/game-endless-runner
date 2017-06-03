#pragma once
#include "CButton.h"

CButton::CButton()
{
	m_buttonSize.x = 0;
	m_buttonSize.y = 0;
	m_buttonSize.w = 0;
	m_buttonSize.h = 0;

	m_imgBtn = nullptr;
}


CButton::~CButton()
{
	delete m_imgBtn;
}

void CButton::init(int posX, int posY, const char* filePath)
{
	m_imgBtn = new CImage();
	m_imgBtn->loadImage(filePath);

	m_buttonSize.x = posX;
	m_buttonSize.y = posY;
	m_buttonSize.w = m_imgBtn->getWidth();
	m_buttonSize.h = m_imgBtn->getHeight();

}

CImage* CButton::getImgBtn()
{
	return m_imgBtn;
}

int CButton::getPosX()
{
	return m_buttonSize.x;
}

int CButton::getPosY()
{
	return m_buttonSize.y;
}

bool CButton::click()
{
	if (CInput::getInstance()->isMousePress() == true)
	{
		if ((m_buttonSize.x <= CInput::getInstance()->getPosMouse().x) && (CInput::getInstance()->getPosMouse().x <= m_buttonSize.x + m_buttonSize.w))
		{
			if ((m_buttonSize.y <= CInput::getInstance()->getPosMouse().y) && (CInput::getInstance()->getPosMouse().y <= m_buttonSize.y + m_buttonSize.h))
			{
				return true;
			}
		}
	}

	return 0;
}