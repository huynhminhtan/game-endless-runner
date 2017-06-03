#pragma once
#include "header.h"

class CImage
{
	SDL_Texture*	m_texture;
	SDL_Rect		m_imageSize;
	
public:
	CImage();
	~CImage();

	bool			loadImage(const char* filePath);
	int				getWidth();
	int				getHeight();
	SDL_Rect		getSize();
	SDL_Texture*	getSDLTexture();
};