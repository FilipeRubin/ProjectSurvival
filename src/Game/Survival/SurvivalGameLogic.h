#pragma once
#include "Game/Common/IGameLogic.h"

class SurvivalGameLogic : public IGameLogic
{
public:
	SurvivalGameLogic();
	void Initialize() override;
	void Process() override;
private:
	bool m_evenFrame = false;

};