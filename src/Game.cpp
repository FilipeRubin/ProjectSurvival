#include "Game.h"

Game* Game::s_pCurrentGame = nullptr;

Game::Game(std::unique_ptr<IGraphics>&& graphics, std::unique_ptr<IGameLogic>&& gameLogic) :
	m_graphics(std::move(graphics)),
	m_gameLogic(std::move(gameLogic))
{
}

IGameLogic& Game::GetGameLogic()
{
	return *m_gameLogic;
}

IGraphics& Game::GetGraphics()
{
	return *m_graphics;
}

void Game::Run()
{
	Initialize();
	RunGameLoop();
	Terminate();
}

Game* Game::GetCurrentGame()
{
	return s_pCurrentGame;
}

void Game::SetCurrentGame(Game* pGame)
{
	s_pCurrentGame = pGame;
}

void Game::Initialize()
{
	IWindow& window = *(m_graphics->GetWindow());
	IRenderer& renderer = *(m_graphics->GetRenderer());

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
	IWindow& window = *(m_graphics->GetWindow());
	IRenderer& renderer = *(m_graphics->GetRenderer());
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
	IWindow& window = *(m_graphics->GetWindow());
	IRenderer& renderer = *(m_graphics->GetRenderer());

	renderer.Terminate();
	window.Terminate();
}
