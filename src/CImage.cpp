#pragma once

#include "CImage.h"
#include "CRenderer.h"

bool CImage::loadImage(const char* filePath)
{
	m_texture = IMG_LoadTexture(CRenderer::getInstance()->getSDLRenderer(), filePath);

	if (m_texture == NULL)
	{
		SDL_Log("Load image failed. Error: %s", IMG_GetError());
		return false;
	}

	m_imageSize.x = m_imageSize.y = 0;
	SDL_QueryTexture(m_texture, NULL, NULL, &m_imageSize.w, &m_imageSize.h);
	
	return true;
}

int CImage::getWidth()
{
	return m_imageSize.w;
}

int CImage::getHeight()
{
	return m_imageSize.h;
}

SDL_Rect CImage::getSize()
{
	return m_imageSize;
}

SDL_Texture * CImage::getSDLTexture()
{
	return m_texture;
}

CImage::CImage():m_texture(nullptr)
{
}

CImage::~CImage()
{
	SDL_DestroyTexture(m_texture);
}