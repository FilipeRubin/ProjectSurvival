#include "SurvivalGameLogic.h"
#include "Game.h"

SurvivalGameLogic::SurvivalGameLogic()
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
		renderer.GetMainViewport().SetClearColor(Color(0.3f, 0.3f, 0.3f));
	}
	else
	{
		renderer.GetMainViewport().SetClearColor(Color(0.0f, 0.0f, 0.0f));
	}
	m_frameCount++;
	if (m_frameCount > 300)
	{
		m_evenFrame = !m_evenFrame;
		m_frameCount = 0;
	}
}
