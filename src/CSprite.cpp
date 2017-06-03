#pragma once
#include "CSprite.h"

CSprite::CSprite()
{
	/*m_frameCurrent = nullptr;*/
	
	m_frameCurrent = new CFrame();
	m_frameCurrent->setFrame(604, 239, 177, 196);
}

CSprite::~CSprite()
{
	//m_fame = new CFrame();
}

bool CSprite::loadSprite(const char* _pathSprite, const char* _pathConfig)
{
	m_texture = IMG_LoadTexture(CRenderer::getInstance()->getSDLRenderer(), _pathSprite);

	if (m_texture == NULL)
	{
		SDL_Log("Load image failed. Error: %s", IMG_GetError());
		return false;
	}

	m_imageSize.x = m_imageSize.y = 0;
	SDL_QueryTexture(m_texture, NULL, NULL, &m_imageSize.w, &m_imageSize.h);

	// load list frame: >> 
	// gọi hàm setFrame

}

void CSprite::drawSprite(int x, int y)
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = m_frameCurrent->getFrame().w; 
	dest.h = m_frameCurrent->getFrame().h;

	SDL_Rect scope;
	scope.x = m_frameCurrent->getFrame().x;
	scope.y = m_frameCurrent->getFrame().y;
	scope.w = m_frameCurrent->getFrame().w;
	scope.h = m_frameCurrent->getFrame().h;

	SDL_RenderCopy(CRenderer::getInstance()->getSDLRenderer(), m_texture, &scope, &dest);
}

////////////////////////////////////////

CFrame::CFrame()
{
	m_frame.x = 0;
	m_frame.y = 0;
	m_frame.w = 0;
	m_frame.h = 0;

	//m_name = nullptr;
}

CFrame::~CFrame()
{

}

void CFrame::setFrame(int _x, int _y, int _w, int _h)
{
	m_frame.x = _x;
	m_frame.y = _y;
	m_frame.w = _w;
	m_frame.h = _h;
}

SDL_Rect CFrame::getFrame()
{
	return m_frame;
}

void CFrame::setName(string _name)
{
	m_name = _name;
}

string CFrame::getName()
{
	return m_name;
}

