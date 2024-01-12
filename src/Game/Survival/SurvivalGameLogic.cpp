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
	IRenderer& renderer = Game::GetCurrentGame()->GetRenderer();
	if (m_evenFrame)
	{
		renderer.SetBackgroundColor(Vector3(0.1f, 0.1f, 0.1f));
	}
	else
	{
		renderer.SetBackgroundColor(Vector3(0.0f, 0.0f, 0.0f));
	}
	m_evenFrame = !m_evenFrame;
}
