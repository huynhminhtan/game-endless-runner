#pragma once
#include "CSprite.h"


CSprite::CSprite()
{
	//m_listFrame

	m_frameCurrent = new CFrame();
	m_frameCurrent->setFrame(604, 239, 177, 196);

	m_indexSprite = 0;
}

CSprite::~CSprite()
{
	//m_fame = new CFrame();
}

bool CSprite::loadSprite(const char* _pathSprite, const char* _pathConfig)
{
	m_texture = IMG_LoadTexture(CRenderer::getInstance()->getSDLRenderer(), _pathSprite);

	if (m_texture == NULL)
	{
		SDL_Log("Load image failed. Error: %s", IMG_GetError());
		return false;
	}

	m_imageSize.x = m_imageSize.y = 0;
	SDL_QueryTexture(m_texture, NULL, NULL, &m_imageSize.w, &m_imageSize.h);

	// gọi hàm setFrame

	// load list frame: >> 
	readJson(_pathConfig);
	setFrame("run-01.png");
}

void CSprite::setFrame(string _nameFrame)
{
	for (list<CFrame>::iterator cf = m_listFrame.begin(); cf != m_listFrame.end(); ++cf)
	{
		if (cf->getName().c_str() == _nameFrame)
		{
			m_frameCurrent->setFrame(cf->getFrame().x, cf->getFrame().y, cf->getFrame().w, cf->getFrame().h);
			break;
		}
	}
	/*	printf("%s: \n", cf->getName().c_str());
		printf("x:%d  y:%d  w:%d  h:%d", cf->getFrame().x, cf->getFrame().y, cf->getFrame().w, cf->getFrame().h);
		printf("\n");*/
}

void CSprite::drawSprite(int x, int y)
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = m_frameCurrent->getFrame().w; // * 0.8
	dest.h = m_frameCurrent->getFrame().h; // * 0.8

	SDL_Rect scope;
	scope.x = m_frameCurrent->getFrame().x;
	scope.y = m_frameCurrent->getFrame().y;
	scope.w = m_frameCurrent->getFrame().w;
	scope.h = m_frameCurrent->getFrame().h;

	SDL_RenderCopy(CRenderer::getInstance()->getSDLRenderer(), m_texture, &scope, &dest);
}

void CSprite::drawSprite(int x, int y, float _scale)
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = m_frameCurrent->getFrame().w * _scale; // * 0.8
	dest.h = m_frameCurrent->getFrame().h * _scale; // * 0.8

	SDL_Rect scope;
	scope.x = m_frameCurrent->getFrame().x;
	scope.y = m_frameCurrent->getFrame().y;
	scope.w = m_frameCurrent->getFrame().w;
	scope.h = m_frameCurrent->getFrame().h;

	SDL_RenderCopy(CRenderer::getInstance()->getSDLRenderer(), m_texture, &scope, &dest);
}

void CSprite::drawSpriteAnimation(int x, int y)
{
	if (m_indexSprite == 0)
	{
		m_indexSprite = 3; // index start frame
	}

	auto l_front = m_listFrame.begin();
	advance(l_front, m_indexSprite);

	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = l_front->getFrame().w;
	dest.h = l_front->getFrame().h;

	SDL_Rect scope;
	scope.x = l_front->getFrame().x;
	scope.y = l_front->getFrame().y;
	scope.w = l_front->getFrame().w;
	scope.h = l_front->getFrame().h;

	SDL_RenderCopy(CRenderer::getInstance()->getSDLRenderer(), m_texture, &scope, &dest);

	m_indexSprite = (m_indexSprite + 1) % (8 + 1); // index end frame
}

void CSprite::drawSpriteAnimation(int x, int y, float _scale)
{
	if (m_indexSprite == 0)
	{
		m_indexSprite = 3; // index start frame
	}

	auto l_front = m_listFrame.begin();
	advance(l_front, m_indexSprite);

	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = l_front->getFrame().w * _scale;
	dest.h = l_front->getFrame().h * _scale;

	SDL_Rect scope;
	scope.x = l_front->getFrame().x;
	scope.y = l_front->getFrame().y;
	scope.w = l_front->getFrame().w;
	scope.h = l_front->getFrame().h;

	SDL_RenderCopy(CRenderer::getInstance()->getSDLRenderer(), m_texture, &scope, &dest);

	m_indexSprite = (m_indexSprite + 1) % (8 + 1); // index end frame
}


void CSprite::readJson(const char* _pathConfig)
{
	const char json[] = R"(
{"frames": {

"hit-wall.png":
{
	"frame": {"x":604,"y":239,"w":177,"h":196},
	"rotated": false,
	"trimmed": false,
	"spriteSourceSize": {"x":0,"y":0,"w":177,"h":196},
	"sourceSize": {"w":177,"h":196}
},
"jump-down.png":
{
	"frame": {"x":0,"y":0,"w":141,"h":234},
	"rotated": false,
	"trimmed": false,
	"spriteSourceSize": {"x":0,"y":0,"w":141,"h":234},
	"sourceSize": {"w":141,"h":234}
},
"jump-up.png":
{
	"frame": {"x":143,"y":0,"w":147,"h":189},
	"rotated": false,
	"trimmed": false,
	"spriteSourceSize": {"x":0,"y":0,"w":147,"h":189},
	"sourceSize": {"w":147,"h":189}
},
"run-01.png":
{
	"frame": {"x":151,"y":239,"w":149,"h":237},
	"rotated": false,
	"trimmed": false,
	"spriteSourceSize": {"x":0,"y":0,"w":149,"h":237},
	"sourceSize": {"w":149,"h":237}
},
"run-02.png":
{
	"frame": {"x":453,"y":239,"w":149,"h":237},
	"rotated": false,
	"trimmed": false,
	"spriteSourceSize": {"x":0,"y":0,"w":149,"h":237},
	"sourceSize": {"w":149,"h":237}
},
"run-03.png":
{
	"frame": {"x":0,"y":239,"w":149,"h":237},
	"rotated": false,
	"trimmed": false,
	"spriteSourceSize": {"x":0,"y":0,"w":149,"h":237},
	"sourceSize": {"w":149,"h":237}
},
"run-04.png":
{
	"frame": {"x":745,"y":0,"w":149,"h":237},
	"rotated": false,
	"trimmed": false,
	"spriteSourceSize": {"x":0,"y":0,"w":149,"h":237},
	"sourceSize": {"w":149,"h":237}
},
"run-05.png":
{
	"frame": {"x":292,"y":0,"w":149,"h":237},
	"rotated": false,
	"trimmed": false,
	"spriteSourceSize": {"x":0,"y":0,"w":149,"h":237},
	"sourceSize": {"w":149,"h":237}
},
"run-06.png":
{
	"frame": {"x":443,"y":0,"w":149,"h":237},
	"rotated": false,
	"trimmed": false,
	"spriteSourceSize": {"x":0,"y":0,"w":149,"h":237},
	"sourceSize": {"w":149,"h":237}
},
"run-07.png":
{
	"frame": {"x":594,"y":0,"w":149,"h":237},
	"rotated": false,
	"trimmed": false,
	"spriteSourceSize": {"x":0,"y":0,"w":149,"h":237},
	"sourceSize": {"w":149,"h":237}
},
"run-08.png":
{
	"frame": {"x":302,"y":239,"w":149,"h":237},
	"rotated": false,
	"trimmed": false,
	"spriteSourceSize": {"x":0,"y":0,"w":149,"h":237},
	"sourceSize": {"w":149,"h":237}
}},
"meta": {
	"app": "http://www.codeandweb.com/texturepacker ",
	"version": "1.0",
	"image": "player.png",
	"format": "RGBA8888",
	"size": {"w":896,"h":476},
	"scale": "1",
	"smartupdate": "$TexturePacker:SmartUpdate:6e8df5801bc1d163b12a2409b6417b50:1/1$"
}
})";

	//printf("Original JSON:\n %s\n", json);

	Document document;
	document.Parse(json);

	const Value& frames = document["frames"];

	for (Value::ConstMemberIterator itr = frames.MemberBegin(); itr != frames.MemberEnd(); ++itr)
	{
		CFrame frameTemp;

		const Value& fx = frames[itr->name.GetString()]["frame"]["x"];
		const Value& fy = frames[itr->name.GetString()]["frame"]["y"];
		const Value& fw = frames[itr->name.GetString()]["frame"]["w"];
		const Value& fh = frames[itr->name.GetString()]["frame"]["h"];

		//printf("%s %d %d %d %d\n ", n.c_str(), fx.GetInt(), fy.GetInt(), fw.GetInt(), fh.GetInt());

		frameTemp.setName(itr->name.GetString());
		frameTemp.setFrame(fx.GetInt(), fy.GetInt(), fw.GetInt(), fh.GetInt());

		m_listFrame.push_back(frameTemp);
	}

	for (list<CFrame>::iterator cf = m_listFrame.begin(); cf != m_listFrame.end(); ++cf)
	{
		printf("%s: \n", cf->getName().c_str());
		printf("x:%d  y:%d  w:%d  h:%d", cf->getFrame().x, cf->getFrame().y, cf->getFrame().w, cf->getFrame().h);
		printf("\n");
	}

}

////////////////////////////////////////

CFrame::CFrame()
{
	m_frame.x = 0;
	m_frame.y = 0;
	m_frame.w = 0;
	m_frame.h = 0;

	//m_name = nullptr;
}

CFrame::~CFrame()
{

}

void CFrame::setFrame(int _x, int _y, int _w, int _h)
{
	m_frame.x = _x;
	m_frame.y = _y;
	m_frame.w = _w;
	m_frame.h = _h;
}

SDL_Rect CFrame::getFrame()
{
	return m_frame;
}

void CFrame::setName(string _name)
{
	m_name = _name;
}

string CFrame::getName()
{
	return m_name;
}

