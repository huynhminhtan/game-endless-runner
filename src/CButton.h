#pragma once
#include "header.h"
#include "CImage.h"
#include "CInput.h"

class CButton
{
public:
	CButton();
	~CButton();

	void		init(int posX, int posY, const char* filePath);

	int			getPosX();
	int			getPosY();

	bool		click();

	CImage*		getImgBtn();
private:

	SDL_Rect	m_buttonSize;
	CImage*		m_imgBtn;
};