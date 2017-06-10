#include "CPlayScence.h"

CPlayScence::CPlayScence()
{
	m_btnBack = nullptr;
	m_posSprite.x = 100;
	m_posSprite.y = 360;

	m_up = false;
	m_down = false;
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

	m_image = new CImage();
	m_image->loadImage("ResourcesEndlessrunner/01_sky_moon.png");

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
		m_down = false;

		printf("asdfasdfasdfsdf");
	}

	if (m_up)
	{
		m_posSprite.y -= 35;

		if (m_posSprite.y < 120)
		{
			m_up = false;
			m_down = true;
		}
	}

	if (m_down)
	{
		m_posSprite.y += 20;

		if (m_posSprite.y > 360)
		{
			m_down = false;
		}
	}
}

void CPlayScence::render()
{
	//CRenderer::getInstance()->renderButton(m_btnBack);
	//CRenderer::getInstance()->drawText(m_text, 10, 10);

	CRenderer::getInstance()->DrawImage(m_image, 2, 2);

	m_sprite->setFrame("jump-up.png");
	m_sprite->drawSprite(m_posSprite.x, m_posSprite.y);

	m_sprite->drawSpriteAnimation(400, 50);

	//	m_spriteHai->drawSprite(350, 140);
}

void CPlayScence::destroy()
{

}