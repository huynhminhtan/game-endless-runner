#pragma once
#include "CScence.h"
#include "CButton.h"
#include "CRenderer.h"
#include "CManageScence.h"
#include "CText.h"
#include "CSprite.h"

class CPlayScence :public CScence
{
public:
	CPlayScence();
	~CPlayScence();

	void init();

	void update(float dt);

	void render();

	void destroy();

private:
	CButton* m_btnBack;
	CText * m_text;

	CImage * m_imgBackground;
	CImage * m_imgBgBush;
	CImage * m_imgBgCity;
	CImage * m_imgBgShadowCity;
	CImage * m_imgBgTree;
	CImage * m_imgBgPlatform;

	CSprite * m_sprite;
	CSprite* m_spriteHai;

	SDL_Rect m_posSprite;
	bool m_up;
	bool m_down;

	int m_posXBgCity;
	int m_posXBgShadowCity;
	int m_posXBgTree;
	int m_posXBgBush;
	int m_posXBgPlatform;

	void moveBackground(CImage * image, int& posX, int posY, int _buffer, float _scale);
	// _numImageDraw: numbers image be draw in frame 
	void moveBackground(CImage * image, int& posX, int posY, int _buffer, int _numImageDraw, float _scale);
};
