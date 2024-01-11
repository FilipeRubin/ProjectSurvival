#include "Game.h"

Game::Game(std::unique_ptr<IRenderer>&& renderer) :
	m_renderer(std::move(renderer))
{
}

void Game::Run()
{
	IRenderer& renderer = *m_renderer;

	renderer.Initialize();

	if (renderer.IsInitialized())
	{
		IWindow& window = m_renderer->GetWindow();
		while (not window.ShouldClose())
		{
			renderer.RenderFrame();
		}
	}
	
	renderer.Terminate();
}
