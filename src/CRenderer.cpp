#pragma once
#include "CRenderer.h"
#include "CImage.h"


//CRenderer* gRenderer = nullptr;
CRenderer* CRenderer::m_instance = nullptr;

CRenderer::CRenderer()
{

}

CRenderer::~CRenderer()
{
	delete m_renderer, m_instance, m_btnImage;
}

void CRenderer::drawRec(int x, int y, int w, int h)
{
	SDL_Rect dstrect;
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = w;
	dstrect.h = h;

	SDL_RenderDrawRect(m_renderer, &dstrect);
}


void  CRenderer::fill()
{

}

void CRenderer::teminate()
{
	//Destroy a renderer
	SDL_DestroyRenderer(m_renderer);
}

void CRenderer::clear()
{
	// set color for background
	renderDrawColor(m_ClearColor.r, m_ClearColor.g, m_ClearColor.b, m_ClearColor.a);
	SDL_RenderClear(m_renderer); // can be fill background

	renderDrawColor(m_DrawColor.r, m_DrawColor.g, m_DrawColor.b, m_DrawColor.a);

}

void CRenderer::present()
{
	// show cached
	SDL_RenderPresent(m_renderer);
}

CRenderer* CRenderer::getInstance()
{
	if (m_instance == nullptr)
		m_instance = new CRenderer();

	return m_instance;
}

bool CRenderer::intitRenderer(SDL_Window* window)
{
	//create a renderer
	m_renderer = SDL_CreateRenderer(window, -1, SDL_WINDOW_SHOWN);

	if (m_renderer == NULL)
	{
		SDL_Log("Could not create render %s", SDL_GetError());
	}

	return m_renderer ? true : false;
}

void CRenderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	m_DrawColor.r = r;
	m_DrawColor.g = g;
	m_DrawColor.b = b;
	m_DrawColor.a = a;
}

void CRenderer::setClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	m_ClearColor.r = r;
	m_ClearColor.g = g;
	m_ClearColor.b = b;
	m_ClearColor.a = a;
}

void CRenderer::renderDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}


SDL_Renderer * CRenderer::getSDLRenderer()
{
	return m_renderer;
}

void CRenderer::DrawImage(CImage* image, int x, int y)
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = image->getWidth();
	dest.h = image->getHeight();

	SDL_RenderCopy(m_renderer, image->getSDLTexture(), &image->getSize(), &dest);
}

void CRenderer::drawText(CText* _text, int x, int y)
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = _text->getWidth();
	dest.h = _text->getHeight();

	SDL_RenderCopy(m_renderer, _text->getSDLTexture(), &_text->getSize(), &dest);

}

void CRenderer::renderButton(CButton* btn)
{
	// Init SDL Image
	//Initialize PNG loading
	//m_btnImage = new CImage();

	//int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	//if (!(IMG_Init(imgFlags) & imgFlags))
	//{
	//	printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	//	return;
	//}
	//
	//if (!(m_btnImage->loadImage(btn->getFilePath())))
	//	return;

	//btn->setWidth(m_btnImage->getWidth());
	//btn->setHeight(m_btnImage->getHeight());

	CRenderer::getInstance()->DrawImage(btn->getImgBtn(), btn->getPosX(), btn->getPosY());

}