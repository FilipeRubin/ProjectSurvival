#include "Game.h"

Game* Game::s_pGame = nullptr;

Game::Game(std::unique_ptr<IGraphics>&& graphics, std::unique_ptr<IGameLogic>&& gameLogic) :
	m_graphics(std::move(graphics)),
	m_gameLogic(std::move(gameLogic))
{
}

void Game::Run()
{
	Initialize();
	RunGameLoop();
	Terminate();
}

IGraphicsManipulator* Game::GetCurrentGraphicsManipulator()
{
	return s_pGame->m_graphics.get();
}

void Game::SetCurrentGame(Game* pGame)
{
	s_pGame = pGame;
}

void Game::Initialize()
{
	IWindowProcessor& window = m_graphics->GetWindowProcessor();
	IRendererProcessor& renderer = m_graphics->GetRendererProcessor();

	window.Initialize();
	renderer.Initialize();

	bool everythingOkay = renderer.IsInitialized() and window.IsInitialized();

	if (not everythingOkay)
	{
		Terminate();
	}
}

void Game::RunGameLoop()
{
	IWindowProcessor& window = m_graphics->GetWindowProcessor();
	IRendererProcessor& renderer = m_graphics->GetRendererProcessor();
	IGameLogic& gameLogic = *m_gameLogic;

	gameLogic.Initialize();
	while (not window.ShouldClose())
	{
		gameLogic.Process();
		renderer.RenderFrame();
		window.Process();
	}
}

void Game::Terminate()
{
	IWindowProcessor& window = m_graphics->GetWindowProcessor();
	IRendererProcessor& renderer = m_graphics->GetRendererProcessor();

	renderer.Terminate();
	window.Terminate();
}
