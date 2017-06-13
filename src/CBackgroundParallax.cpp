#pragma once
#include "CBackgroundParallax.h"

CBackgroundParallax* CBackgroundParallax::m_instance = nullptr;

CBackgroundParallax::CBackgroundParallax()
{
	m_posXBgCity = 0;
	m_posXBgShadowCity = 0;
	m_posXBgTree = 0;
	m_posXBgBush = 0;
	m_posXBgPlatform = 0;

	m_imgBackground = nullptr;
	m_imgBgCity = nullptr;
	m_imgBgShadowCity = nullptr;
	m_imgBgTree = nullptr;
	m_imgBgBush = nullptr;
	m_imgBgPlatform = nullptr;
}

CBackgroundParallax::~CBackgroundParallax()
{

}

CBackgroundParallax* CBackgroundParallax::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new CBackgroundParallax();
	}

	return m_instance;
}

void CBackgroundParallax::init()
{
	m_imgBackground = new CImage();
	m_imgBackground->loadImage("ResourcesEndlessrunner/01_sky_moon.png");

	m_imgBgCity = new CImage();
	m_imgBgCity->loadImage("ResourcesEndlessrunner/04_city.png");

	m_imgBgShadowCity = new CImage();
	m_imgBgShadowCity->loadImage("ResourcesEndlessrunner/03_city.png");

	m_imgBgTree = new CImage();
	m_imgBgTree->loadImage("ResourcesEndlessrunner/05_trees.png");

	m_imgBgBush = new CImage();
	m_imgBgBush->loadImage("ResourcesEndlessrunner/05_bush.png");

	m_imgBgPlatform = new CImage();
	m_imgBgPlatform->loadImage("ResourcesEndlessrunner/platform.png");
}

void CBackgroundParallax::draw()
{
	moveBackground(m_imgBgShadowCity, m_posXBgShadowCity, 100, 4, 2, 0.65);
	moveBackground(m_imgBgCity, m_posXBgCity, 100, 5, 2, 0.65);
	moveBackground(m_imgBgTree, m_posXBgTree, 200, 8, 3, 0.5);
	moveBackground(m_imgBgBush, m_posXBgBush, 465, 10, 3, 0.5);
	moveBackground(m_imgBgPlatform, m_posXBgPlatform, 550, 5, 22, 0.7);
}

void CBackgroundParallax::moveBackground(CImage* image, int& posX, int posY, int _buffer, float _scale)
{
	CRenderer::getInstance()->DrawImage(image, posX -= _buffer, posY, _scale);
	CRenderer::getInstance()->DrawImage(image, posX + image->getSize().w * _scale, posY, _scale);

	// set to posX
	if (posX < -(image->getSize().w * _scale))
	{
		posX = 0;
	}

}

void CBackgroundParallax::moveBackground(CImage* image, int& posX, int posY, int _buffer, int _numImageDraw, float _scale)
{
	CRenderer::getInstance()->DrawImage(image, posX -= _buffer, posY, _scale);

	int posXUpdate = posX;

	for (int i = 1; i < _numImageDraw; i++)
	{
		posXUpdate += image->getSize().w * _scale;

		CRenderer::getInstance()->DrawImage(image, posXUpdate, posY, _scale);
	}

	// set to posX
	if (posX < -((image->getSize().w * _scale)))
	{
		posX = -_buffer;
	}

}