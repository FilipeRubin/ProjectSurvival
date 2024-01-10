#include "Game.h"
#include <GLFW/glfw3.h>
#include <Renderer/OpenGL/OGLShader.h>

Game::Game(std::unique_ptr<IRenderer>&& renderer) :
	m_renderer(std::move(renderer)),
	m_meshes(ContiguousArray<IMesh*>())
{
}

void Game::Run()
{
	IRenderer& renderer = *m_renderer;

	renderer.Initialize();

	if (renderer.IsInitialized())
	{
		std::unique_ptr<IShader> shaderPtr = renderer.CreateShader();
		IShader& shader = *shaderPtr.get();
		shader.Compile();
		while (renderer.IsRunning())
		{
			for (int i = 0; i < m_meshes.Length(); i++)
			{
				m_meshes[i]->Render();
			}

			renderer.RenderFrame();
		}
	}
	
	renderer.Cleanup();
}
