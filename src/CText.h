#pragma once
#include "header.h"
#include "CRenderer.h"

class CText
{
public:
	CText();
	~CText();

	void init( const char* _fontStyle, int _fontSize);
	void loadText(const char* _str);
	
	int getWidth();
	int getHeight();

	SDL_Rect getSize();
	SDL_Texture* getSDLTexture();

private:
	TTF_Font* m_font;
	SDL_Surface* m_surface;
	SDL_Texture* m_texture;

	SDL_Rect m_size;
};