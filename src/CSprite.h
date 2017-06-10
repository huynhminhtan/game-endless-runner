#pragma once
#include "CRenderer.h"
#include <string>
#include <list>

#include "../lib/rapidjson/document.h"
#include "../lib/rapidjson/writer.h"
#include "../lib/rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;

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
	void drawSprite(int x, int y, float _scale);

	void drawSpriteAnimation(int x, int y);
	void drawSpriteAnimation(int x, int y, float _scale);

	void setFrame(string _nameFrame);

private:
	SDL_Texture*	m_texture;
	SDL_Rect		m_imageSize;

	list<CFrame> m_listFrame;

	CFrame* m_frameCurrent;
	void readJson(const char*);

	int m_indexSprite;
	
};




