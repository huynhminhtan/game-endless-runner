#pragma once
#include "CManageScence.h"


CManageScence* CManageScence::m_instance = nullptr;

CManageScence* CManageScence::getInstance()
{
	if (m_instance == nullptr)
		m_instance = new CManageScence();

	return m_instance;
}

void CManageScence::setScenceCurrent(CScence* _scence)
{
	m_scenceCurrent = _scence;
}

void CManageScence::init()
{
	//m_scenceCurrent->init();
}

void CManageScence::render()
{
	m_scenceCurrent->render();
}

void CManageScence::update(float dt)
{
	if (m_scenceNext != nullptr)
	{
		m_scenceCurrent->destroy();
		delete m_scenceCurrent;

		m_scenceCurrent = m_scenceNext;
		m_scenceCurrent->init();

		m_scenceNext = nullptr;
	}
	
	m_scenceCurrent->update(dt);
}

void CManageScence::startGame(CScence* _scn)
{
	m_scenceCurrent = _scn;
	m_scenceCurrent->init();

	m_scenceNext = nullptr;
}

void CManageScence::setScenceNext(CScence* _scn)
{
	m_scenceNext = _scn;
}