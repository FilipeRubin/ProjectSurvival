#include "Game.h"
#include "Game/Survival/SurvivalGameLogic.h"
#include "Rendering/OpenGL/OGLGraphics.h"

int main()
{
	using std::unique_ptr;
	using std::make_unique;
	using std::move;

	unique_ptr<IGraphics> graphics = make_unique<OGLGraphics>();
	unique_ptr<IGameLogic> gameLogic = make_unique<SurvivalGameLogic>();

	Game game = Game(move(graphics), move(gameLogic));
	Game::SetCurrentGame(&game);
	game.Run();
	Game::SetCurrentGame(nullptr);

	return 0;
}
