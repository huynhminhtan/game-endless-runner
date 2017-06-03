#include "header.h"

class CMusic
{
public:
	CMusic();
	~CMusic();

	void intit(const char* _filePath);
	
	void play(int _loop);
	void stop();
	void pause();
	void resume();

private:

//	Mix_Chunk* m_chunk;
	Mix_Music* m_music;

};