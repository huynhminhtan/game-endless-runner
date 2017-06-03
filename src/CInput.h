#pragma once

#include "header.h"

class CInput
{
public:
	CInput();
	~CInput();

	static CInput* getInstance();

	void setInputEvent(SDL_Event& mainEvent);

	bool isPressKeyDown(SDL_Keycode key);
	bool isMousePress();

	SDL_Point getPosMouse();

private:
	static CInput* m_instance;
	SDL_Event m_event;
};
