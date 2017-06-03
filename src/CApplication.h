#pragma once
#include "header.h"
#include "CRenderer.h"
#include <time.h> 
#include "CScence.h"
#include "CInput.h"
#include "CScence.h"
#include "CManageScence.h"


class CApplication
{
public:
	CApplication();
	~CApplication();

	bool init(int w = 800, int h = 600, const char* title = "Engine");
	void run(const int& fps);
	void teminate();

	void setStartScene(CScence* scene);

	/*void setPosRec(int x, int y);

	CImage* m_image;

	CButton* m_btnPlay;
	CButton* m_btnExit;
	CButton* m_btnBack;

	CScence* mainScence;
	CScence* playScence;*/

private:
	SDL_Window* m_window;
	bool m_isRunning;

	CScence*	m_currentScene;

	//SDL_Point m_posRec;

	void renderer();
	void update(float);
	void processEvent(SDL_Event&);

	
};

//extern int Vx;
//extern int Vy;
