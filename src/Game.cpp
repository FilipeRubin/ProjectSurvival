#include "Game.h"
#include <GLFW/glfw3.h>
#include <Renderer/OpenGL/OGLShader.h>

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
		while (renderer.IsRunning())
		{
			

			renderer.RenderFrame();
		}
	}
	
	renderer.Cleanup();
}
