#include "Game.h"

Game* Game::s_pCurrentGame = nullptr;

Game::Game(std::unique_ptr<IRenderer>&& renderer, std::unique_ptr<IWindow>&& window, std::unique_ptr<IGameLogic>&& gameLogic) :
	m_renderer(std::move(renderer)),
	m_window(std::move(window)),
	m_gameLogic(std::move(gameLogic))
{
}

IRenderer& Game::GetRenderer()
{
	return *m_renderer;
}

IWindow& Game::GetWindow()
{
	return *m_window;
}

IGameLogic& Game::GetGameLogic()
{
	return *m_gameLogic;
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
	m_window->Initialize();
	m_renderer->Initialize();

	bool everythingOkay = m_renderer->IsInitialized() and m_window->IsInitialized();

	if (not everythingOkay)
	{
		Terminate();
	}
}

void Game::RunGameLoop()
{
	m_gameLogic->Initialize();
	while (not m_window->ShouldClose())
	{
		m_gameLogic->Process();
		m_renderer->RenderFrame();
		m_window->Process();
	}
}

void Game::Terminate()
{
	m_renderer->Terminate();
	m_window->Terminate();
}
