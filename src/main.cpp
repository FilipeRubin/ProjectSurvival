#include "Game.h"
#include "Renderer/OpenGL/OGLRenderer.h"

int main()
{
	using std::unique_ptr;
	using std::make_unique;

	unique_ptr<IRenderer> renderer = make_unique<OGLRenderer>();
	Game game = Game(std::move(renderer));
	game.Run();

	return 0;
}