#pragma once
#include "CRenderer.h"
#include <string>
using namespace std;

class CFrame
{
public:
	CFrame();
	~CFrame();

	void setFrame(int _x, int _y, int _w, int _h);
	SDL_Rect getFrame();

	void setName(string _name);
	string getName();

private:
	SDL_Rect m_frame;
	string m_name;
};


class CSprite
{
public:
	CSprite();
	~CSprite();

	bool loadSprite(const char* _pathSprite, const char* _pathConfig);

	void drawSprite(int x, int y);

	void setFrame(const char* _nameFrame);

private:
	SDL_Texture*	m_texture;
	SDL_Rect		m_imageSize;

	/*CFrame* m_fame;
	*/
	CFrame* m_frameCurrent;
};




