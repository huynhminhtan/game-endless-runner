#include "header.h"

class CSpriteAni
{
public:
	CSpriteAni();
	~CSpriteAni();

	bool loadSpriteAni(const char* _pathSprite, const char* _pathConfig);

	void drawSpriteAni(int _posX, int _posY);

private:
	SDL_Texture*	m_texture;
	SDL_Rect		m_imageSize;

};