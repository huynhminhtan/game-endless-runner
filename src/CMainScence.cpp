#pragma once
#include "CMainScence.h"

void CMainScence::init()
{
	m_btnPlay = new CButton();
	m_btnPlay->init(230, 80, "btnPlay.png");


	m_btnExit = new CButton();
	m_btnExit->init(230, 200, "btnExit.png");

	m_music = new CMusic();
	m_music->intit("nhac.mp3");
	m_music->play(1);
}

void CMainScence::render()
{
	CRenderer::getInstance()->renderButton(m_btnPlay);
	CRenderer::getInstance()->renderButton(m_btnExit);
}

void CMainScence::update(float dt)
{

	if (m_btnPlay->click())
	{
		CManageScence::getInstance()->setScenceNext(new CPlayScence());
	}

	if (CInput::getInstance()->isPressKeyDown(SDLK_UP))
	{
		m_music->stop();
	}

	if (CInput::getInstance()->isPressKeyDown(SDLK_DOWN))
	{
		m_music->play(1);
	}
}

void CMainScence::destroy()
{

}

CMainScence::CMainScence()
{
	m_btnPlay = nullptr;
	m_btnExit = nullptr;
}

CMainScence::~CMainScence()
{
	delete m_btnExit, m_btnPlay;
}
