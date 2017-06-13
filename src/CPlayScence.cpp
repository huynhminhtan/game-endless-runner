#include "CPlayScence.h"

CPlayScence::CPlayScence()
{
	m_btnBack = nullptr;
	m_posSprite.x = 100;
	m_posSprite.y = 390;

	m_up = false;
	m_down = false;

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

CPlayScence::~CPlayScence()
{

}

void CPlayScence::init()
{
	/*m_btnBack = new CButton();
	m_btnBack->init(230, 180, "btnExit.png");*/

	/*m_text = new CText();
	m_text->init("VeraMoBd.ttf", 50);
	m_text->loadText("mtSiniChi");*/

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

	m_sprite = new CSprite();
	m_sprite->loadSprite("ResourcesEndlessrunner/player.png", "sd");


	//m_spriteHai = new CSprite();
	//m_spriteHai->loadSprite("spritestrip.png", 250, 260);
}

void CPlayScence::update(float dt)
{
	/*if (m_btnBack->click())
	{
	CManageScence::getInstance()->setScenceNext(new CMainScence());
	}*/

	if (CInput::getInstance()->isPressKeyDown(SDLK_UP))
	{
		m_up = true;
	}

	if (m_up)
	{
		if (!m_down)
			m_posSprite.y -= 10;

		printf("afasdf");

		if (m_posSprite.y < 170)
		{
			m_up = false;
			m_down = true;
		}
	}

	if (m_down)
	{
		m_posSprite.y += 5;

		if (m_posSprite.y > 390)
		{
			m_down = false;
		}
	}
}

void CPlayScence::render()
{
	//CRenderer::getInstance()->renderButton(m_btnBack);
	//CRenderer::getInstance()->drawText(m_text, 10, 10);

	CRenderer::getInstance()->DrawImage(m_imgBackground, 0, 0, 0.65);

	moveBackground(m_imgBgShadowCity, m_posXBgShadowCity, 100, 4, 2, 0.65);
	moveBackground(m_imgBgCity, m_posXBgCity, 100, 5, 2, 0.65);
	moveBackground(m_imgBgTree, m_posXBgTree, 200, 8, 3, 0.5);
	moveBackground(m_imgBgBush, m_posXBgBush, 465, 10, 3, 0.5);
	moveBackground(m_imgBgPlatform, m_posXBgPlatform, 550, 5, 22, 0.7);

	if (m_up && !m_down)
	{
		m_sprite->setFrame("jump-up.png");
		m_sprite->drawSprite(m_posSprite.x, m_posSprite.y, 0.8);
	}

	if (!m_up && !m_down)
	{
		m_sprite->drawSpriteAnimation(100, m_posSprite.y, 0.8);
	}

	if (m_down)
	{
		m_sprite->setFrame("jump-down.png");
		m_sprite->drawSprite(m_posSprite.x, m_posSprite.y, 0.8);
	}

	//	m_spriteHai->drawSprite(350, 140);
}

void CPlayScence::moveBackground(CImage* image, int& posX, int posY, int _buffer, float _scale)
{
	CRenderer::getInstance()->DrawImage(image, posX -= _buffer, posY, _scale);
	CRenderer::getInstance()->DrawImage(image, posX + image->getSize().w * _scale, posY, _scale);

	// set to posX
	if (posX < -(image->getSize().w * _scale))
	{
		posX = 0;
	}

}

void CPlayScence::moveBackground(CImage* image, int& posX, int posY, int _buffer, int _numImageDraw, float _scale)
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

void CPlayScence::destroy()
{

}

