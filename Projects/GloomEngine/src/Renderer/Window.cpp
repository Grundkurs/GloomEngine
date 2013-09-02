
#include "Core/Logger.h"
#include "Renderer/Window.h"
#include "Renderer/Renderer.h"
#include "Core/GloomEngineConfig.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace gloom
{

Window::Window() :
	mpWindow(nullptr)
	{

	}

//Window::Window(Renderer& renderer) :
//	mRenderer(renderer),
//	mWindow(nullptr)
//	{
//	mWindow = glfwCreateWindow(800, 600, "Untitled", 0, mRenderer.baseContext());
//	}

Window::~Window()
	{
	if ( mpWindow )
		{
		glfwDestroyWindow(mpWindow);
		}
	glfwTerminate();
	}

bool Window::init(GloomEngineConfig * pConfig)
	{
	LogFuncBegin()

	if ( pConfig == nullptr )
		{
		LogFailure("GloomEngineConfig pointer is null, can't load window.")
		return false;
		}

	if ( !glfwInit() )
		{
		LogFailure("glfwInit failed to init")
		return false;
		}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, pConfig->getGLVersionMajor() );
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, pConfig->getGLVersionMinor() );
	glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, pConfig->getGLCoreProfile() ? GL_TRUE : GL_FALSE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_SAMPLES, pConfig->getGLAASamples() );

	mpWindow = glfwCreateWindow( pConfig->getScreenWidth(), pConfig->getScreenHeight(), "Gloom Engine", NULL, NULL );

	if ( !mpWindow )
		{
		LogFailure("glfw3 create window failed to create window")
		glfwTerminate();
		return false;
		}

	activate();

	LogFuncEndSuccess()
	return true;
	}

//Renderer& Window::renderer()
//	{
//	return mRenderer;
//	}

void Window::setTitle(std::string const& title)
	{
	glfwSetWindowTitle(mpWindow, title.c_str());
	}

void Window::setSize(unsigned width, unsigned height)
	{
	glfwSetWindowSize(mpWindow, width, height);
	}

unsigned Window::width() const
	{
	int w;
	glfwGetWindowSize(mpWindow, &w, 0);
	return w;
	}

unsigned Window::height() const
	{
	int h;
	glfwGetWindowSize(mpWindow, 0, &h);
	return h;
	}

void Window::setVisible(bool visible)
	{
	if(visible)
		{
		glfwShowWindow(mpWindow);
		}
	else
		{
		glfwHideWindow(mpWindow);
		}
	}

bool Window::isOpen() const
	{
	return !glfwWindowShouldClose(mpWindow);
	}

void Window::activate()
	{
	glfwMakeContextCurrent(mpWindow);
	}

void Window::display()
	{
	glfwSwapBuffers(mpWindow);
	}

}
