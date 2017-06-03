#include "CMusic.h"

CMusic::CMusic()
{
	//m_chunk = nullptr;
	m_music = nullptr;
}

CMusic::~CMusic()
{
	Mix_CloseAudio();
}

void CMusic::intit(const char* _filePath)
{
	m_music = Mix_LoadMUS(_filePath);

	if (m_music == NULL)
	{
		printf("%s", Mix_GetError());
	}
}

void CMusic::play(int _loop)
{
	Mix_PlayMusic(m_music, _loop);
}

void CMusic::stop()
{
	Mix_HaltMusic();
}

void CMusic::pause()
{
	Mix_PauseMusic();
}


void CMusic::resume()
{
	Mix_PauseMusic();
}