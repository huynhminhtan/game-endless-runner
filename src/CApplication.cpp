#pragma once
#include "CApplication.h"

//int Vx = 0;
//int Vy = 0;

CApplication::CApplication()
{
	//initializes  the subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		SDL_Log("Unable to initialize SDL %s\n", SDL_GetError());
		return;
	}
}

CApplication::~CApplication()
{
	//delete m_btnPlay, m_btnExit, m_btnBack, playScence, mainScence;
}

bool CApplication::init(int height, int width, const char* title)
{
	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, SDL_WINDOW_SHOWN);
	if (m_window == NULL)
	{
		SDL_Log("Could not create window %s", SDL_GetError());
		return false;
	}
	// Create renderer
	CRenderer::getInstance()->intitRenderer(m_window);
	CRenderer::getInstance()->setDrawColor(255, 0, 0, 0);
	CRenderer::getInstance()->setClearColor(237, 242, 239, 0);



	// Init SDL Image
	//Initialize PNG loading

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	//CManageScence::getInstance()->init();
	//m_currentScene->init();

	// init music
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
	{
		printf("%s", Mix_GetError());
	}

	//Initialize the truetype font API.
	if (TTF_Init() < 0)
	{
		SDL_Log("%s", TTF_GetError());
		return -1;
	}

	//setPosRec(10, 10);
	//m_image = new CImage();
	//m_image->loadImage("loaded.png");


	//// init Button
	//m_btnPlay = new CButton("btnPlay.png");
	//m_btnExit = new CButton("btnExit.png");
	//m_btnBack = new CButton("btnBack.png");

	//// init Scence
	//playScence = new CScence();
	//mainScence = new CScence();

	return true;
}

void CApplication::run(const int& fps)
{
	SDL_Event mainEvent;
	m_isRunning = true;

	// Frame per second
	float delayTime = CLOCKS_PER_SEC / fps;

	clock_t timeRender = delayTime;
	clock_t timeStart;
	clock_t timeEnd;

	while (m_isRunning)
	{
		timeStart = clock();

		processEvent(mainEvent);
		update(timeRender);

		CRenderer::getInstance()->clear();
		renderer();
		CRenderer::getInstance()->present();

		timeEnd = clock();

		timeRender = (int)((timeEnd - timeStart) / CLOCKS_PER_SEC);

		if (timeRender < delayTime)
		{
			SDL_Delay(delayTime - timeRender);
			timeRender = delayTime;
		}
	} // end while is running
}

void CApplication::teminate()
{
	//Destroy a window.
	SDL_DestroyWindow(m_window);
	SDL_Quit();
	TTF_Quit();
}

void CApplication::renderer()
{
	//m_currentScene->render();
	CManageScence::getInstance()->render();
	//if (m_btnPlay->isClicked == true)
	//{
	//	playScence->renderImage("loaded.png");
	//	mainScence->renderButton(m_btnBack, 230, 380);
	//}
	//else
	//{
	//	//mainScence->renderButton(m_btnPlay, 230, 80);
	//	mainScence->renderButton(m_btnExit, 230, 250);
	//}

	//CRenderer::getInstance()->DrawImage(m_image, 10, 10);
	//CRenderer::getInstance()->drawRec(m_posRec.x, m_posRec.y, 100, 100);
}

void CApplication::update(float delta)
{
	CManageScence::getInstance()->update(delta);
	//m_currentScene->update(delta);
	//	CManageScence::getInstance()->getScenceCurrent()->update(delta);
	/*
	m_posRec.x += 0.5 * delta;

	// set default
	if (m_posRec.x > 800)
	{
	m_posRec.x = 0;
	}

	*/
}

void CApplication::processEvent(SDL_Event& mainEvent)
{
	while (SDL_PollEvent(&mainEvent))
	{
		/*
		if (mainEvent.type == SDL_MOUSEMOTION || mainEvent.type == SDL_MOUSEBUTTONDOWN || mainEvent.type == SDL_MOUSEBUTTONUP)
		{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);

		if (mainEvent.button.button == SDL_BUTTON_LEFT)
		{

		}
		}
		*/

		CInput::getInstance()->setInputEvent(mainEvent);

		if (mainEvent.type == SDL_QUIT)
		{
			m_isRunning = false;
		}
	}
}
//
//void CApplication::setPosRec(int x, int y)
//{
//	m_posRec.x = x;
//	m_posRec.y = y;
//}

void CApplication::setStartScene(CScence* scene)
{
	//m_currentScene = scene;
	CManageScence::getInstance()->startGame(scene);
}

