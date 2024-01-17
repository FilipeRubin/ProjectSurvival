#include "SurvivalGameLogic.h"
#include "Game.h"

SurvivalGameLogic::SurvivalGameLogic() :
	m_evenFrame(false)
{
}

void SurvivalGameLogic::Initialize()
{
}

void SurvivalGameLogic::Process()
{
	IRendererManipulator& renderer = Game::GetCurrentGraphicsManipulator()->GetRendererManipulator();
	if (m_evenFrame)
	{
		renderer.SetClearColor(Color(0.1f, 0.1f, 0.1f));
	}
	else
	{
		renderer.SetClearColor(Color(0.0f, 0.0f, 0.0f));
	}
	m_evenFrame = !m_evenFrame;
}
