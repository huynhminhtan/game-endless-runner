#pragma once
#include "header.h"
#include "CButton.h"
#include "CText.h"

class CImage;
class CText;
class CRenderer
{
public:
	
	void drawRec(int x, int y, int w, int h);
	void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void setClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void renderDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void drawColor();
	void fill();
	void teminate();

	static CRenderer* getInstance();

	void clear();
	void present();
	
	bool intitRenderer(SDL_Window*);
	void DrawImage(CImage* image, int x, int y);


	void drawText(CText* _text, int x, int y);

	SDL_Renderer* getSDLRenderer();

	void renderButton(CButton*);

private:
	static CRenderer*	m_instance;
	CRenderer();
	~CRenderer();

	CImage* m_btnImage;

	SDL_Color			m_DrawColor;
	SDL_Color			m_ClearColor;

	SDL_Renderer*		m_renderer;
};

//extern CRenderer* gRenderer;

