#include "CPlayScence.h"

CPlayScence::CPlayScence()
{
	m_btnBack = nullptr;
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
}

void CPlayScence::render()
{
	//CRenderer::getInstance()->renderButton(m_btnBack);
	//CRenderer::getInstance()->drawText(m_text, 10, 10);
	CRenderer::getInstance()->DrawImage(m_image, 2, 2);

	m_sprite->drawSprite(150, 40);

//	m_spriteHai->drawSprite(350, 140);
}

void CPlayScence::destroy()
{

}