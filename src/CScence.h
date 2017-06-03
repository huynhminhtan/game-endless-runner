#pragma once

class CScence
{
public:
	virtual void init() = 0;
	virtual void update(float dt) = 0;
	virtual void render() = 0;
	virtual void destroy() = 0;
};