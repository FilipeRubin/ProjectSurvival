#include "OpenGLViewport.h"
#include <glad/glad.h>

void OpenGLViewport::SetClearColor(const Color& color)
{
	glClearColor(color.r, color.g, color.b, color.a);
}
