#pragma once
#include "CScence.h"
#include "CPlayScence.h"
#include "CMainScence.h"

class CManageScence
{
public:

	void init();

	static CManageScence* getInstance();
	
	void setScenceCurrent(CScence*);
	void setScenceNext(CScence*);
	void startGame(CScence*);

	void render();
	void update(float dt);

private:

	CScence* m_scenceCurrent;
	CScence* m_scenceNext;
	static CManageScence* m_instance;
};