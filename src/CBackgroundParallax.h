#pragma once
#include "CImage.h"
#include "CRenderer.h"

//class CImage;
class CBackgroundParallax
{
private:
	CImage * m_imgBackground;
	CImage * m_imgBgBush;
	CImage * m_imgBgCity;
	CImage * m_imgBgShadowCity;
	CImage * m_imgBgTree;
	CImage * m_imgBgPlatform;

	int m_posXBgCity;
	int m_posXBgShadowCity;
	int m_posXBgTree;
	int m_posXBgBush;
	int m_posXBgPlatform;

	static CBackgroundParallax* m_instance;

public:
	CBackgroundParallax();
	~CBackgroundParallax();

	void init();
	void draw();

	static CBackgroundParallax* getInstance();

	void moveBackground(CImage * image, int& posX, int posY, int _buffer, float _scale);
	void moveBackground(CImage * image, int& posX, int posY, int _buffer, int _numImageDraw, float _scale);
};