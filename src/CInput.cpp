#pragma once
#include "CInput.h"


CInput* CInput::m_instance = nullptr;

CInput::CInput()
{
}

CInput::~CInput()
{
}

CInput* CInput::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new CInput();
	}

	return m_instance;
}

void CInput::setInputEvent(SDL_Event& e)
{
	m_event = e;

	//if (mainEvent.type == SDL_MOUSEMOTION || mainEvent.type == SDL_MOUSEBUTTONDOWN || mainEvent.type == SDL_MOUSEBUTTONUP)
	//{
	//	//Get mouse position
	//	int x, y;
	//	SDL_GetMouseState(&x, &y);

	//	if (mainEvent.button.button == SDL_BUTTON_LEFT)
	//	{

	//	}
	//}

	//if (mainEvent.type == SDL_QUIT)
	//{
	//	m_isRunning = false;
	//}
}

bool CInput::isMousePress()
{
	if (m_event.type == SDL_MOUSEBUTTONDOWN/* || m_event.type == SDL_MOUSEBUTTONUP*/)
		return true;
	return false;
}

SDL_Point CInput::getPosMouse()
{
	SDL_Point pos;

	SDL_GetMouseState(&pos.x, &pos.y);

	return pos;
}

bool CInput::isPressKeyDown(SDL_Keycode key)
{
	if (m_event.type == SDL_KEYDOWN)
	{
		if (m_event.key.keysym.sym == key)
			return true;
	}

	return false;
}