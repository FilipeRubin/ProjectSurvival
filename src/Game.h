#pragma once
#include "Game/Common/IGameLogic.h"
#include "Rendering/Common/IGraphics.h"
#include <memory>

class Game
{
public:
	static IGraphicsManipulator* GetCurrentGraphicsManipulator();
	static void SetCurrentGame(Game* pGame);

	Game(std::unique_ptr<IGraphics>&& graphics, std::unique_ptr<IGameLogic>&& gameLogic);
	void Run();
private:
	static Game* s_pGame;

	std::unique_ptr<IGraphics> m_graphics;
	std::unique_ptr<IGameLogic> m_gameLogic;

	void Initialize();
	void RunGameLoop();
	void Terminate();
};
