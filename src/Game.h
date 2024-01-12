#pragma once
#include "Game/Common/IGameLogic.h"
#include "Rendering/Common/IRenderer.h"
#include <memory>

class Game
{
public:
	static Game* GetCurrentGame();
	static void SetCurrentGame(Game* pGame);

	Game(std::unique_ptr<IRenderer>&& renderer, std::unique_ptr<IWindow>&& window, std::unique_ptr<IGameLogic>&& gameLogic);
	IRenderer& GetRenderer();
	IWindow& GetWindow();
	IGameLogic& GetGameLogic();
	void Run();
private:
	static Game* s_pCurrentGame;

	std::unique_ptr<IRenderer> m_renderer;
	std::unique_ptr<IWindow> m_window;
	std::unique_ptr<IGameLogic> m_gameLogic;
	void Initialize();
	void RunGameLoop();
	void Terminate();
};