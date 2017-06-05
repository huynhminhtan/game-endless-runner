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
	CImage * m_image;

	CSprite * m_sprite;
	CSprite* m_spriteHai;

	SDL_Rect m_posSprite;
	bool m_up;
	bool m_down;
};
