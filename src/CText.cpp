#pragma once
#include "CText.h"

CText::CText()
{
	m_font = nullptr;
	m_texture = nullptr;
	m_surface = nullptr;

	m_size.x = 0;
	m_size.y = 0;
	m_size.h = 0;
	m_size.w = 0;
}

CText::~CText()
{
	SDL_FreeSurface(m_surface);
	SDL_DestroyTexture(m_texture);
}

void CText::init(const char* _fontStyle, int _fontSize)
{
	m_font = TTF_OpenFont(_fontStyle, _fontSize);
}

void CText::loadText(const char* str)
{
	// set color
	SDL_Color fg = { 0, 0, 255 };

	m_surface = TTF_RenderText_Solid(m_font, str, fg);

	m_texture = SDL_CreateTextureFromSurface(CRenderer::getInstance()->getSDLRenderer(), m_surface);
	SDL_FreeSurface(m_surface);

	m_size.x = 0;
	m_size.y = 0;
	TTF_SizeText(m_font, str, &m_size.w, &m_size.h);
}

int CText::getHeight()
{
	return m_size.h;
}

int CText::getWidth()
{
	return m_size.w;
}

SDL_Rect CText::getSize()
{
	return m_size;
}

SDL_Texture* CText::getSDLTexture()
{
	return m_texture;
}