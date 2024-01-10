#pragma once
#include "Renderer/IRenderer.h"
#include "Utility/ContiguousArray.h"

class Game
{
public:
	Game(std::unique_ptr<IRenderer>&& renderer);
	void Run();
private:
	std::unique_ptr<IRenderer> m_renderer;
};