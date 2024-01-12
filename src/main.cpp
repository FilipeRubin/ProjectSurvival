#include "Game.h"
#include "Game/Survival/SurvivalGameLogic.h"
#include "Rendering/OpenGL/OGLRenderer.h"
#include "Rendering/OpenGL/OGLWindow.h"

int main()
{
	using std::unique_ptr;
	using std::make_unique;
	using std::move;

	unique_ptr<IRenderer> renderer = make_unique<OGLRenderer>();
	unique_ptr<IWindow> window = make_unique<OGLWindow>();
	unique_ptr<IGameLogic> gameLogic = make_unique<SurvivalGameLogic>();

	Game game = Game(move(renderer), move(window), move(gameLogic));
	Game::SetCurrentGame(&game);
	game.Run();

	return 0;
}