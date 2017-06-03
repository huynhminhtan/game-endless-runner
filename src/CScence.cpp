#pragma once
#include "CScence.h"


CScence::CScence()
{
	m_img = new CImage();
}

CScence::~CScence()
{
	delete m_img;
}


void CScence::renderButton(CButton* btn, int posX, int posY)
{
	if (btn == nullptr)
	{
		printf("Error! New button.\n");
		return;
	}

	btn->init(posX, posY);

	CRenderer::getInstance()->drawButton(btn);
}

void CScence::renderImage(const char* filePath)
{
	
	m_img->loadImage(filePath);

	CRenderer::getInstance()->DrawImage(m_img, 10, 10);
}