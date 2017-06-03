#pragma once
#include "CScence.h"
#include "CButton.h"
#include "CRenderer.h"
#include "CImage.h"
#include "CManageScence.h"
#include "CInput.h"
#include "CMusic.h"

class CMainScence : public CScence
{
public:
	void init();

	void update(float dt);

	void render();

	void destroy();

	CMainScence();

	~CMainScence();

private:

	CButton* m_btnPlay;
	CButton* m_btnExit;

	CMusic* m_music;
};