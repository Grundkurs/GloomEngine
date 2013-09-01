#include "include/Renderer/Window.h"
#include "include/Renderer/Renderer.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace lee
{

Window::Window(Renderer& renderer) :
	//mRenderer(renderer),
	mWindow(nullptr)
	{
	mWindow = glfwCreateWindow(800, 600, "Untitled", 0, mRenderer.baseContext());
	}

Window::~Window()
	{
	glfwDestroyWindow(mWindow);
	}

Renderer& Window::renderer()
	{
	return mRenderer;
	}

void Window::setTitle(std::string const& title)
	{
	glfwSetWindowTitle(mWindow, title.c_str());
	}

void Window::setSize(unsigned width, unsigned height)
	{
	glfwSetWindowSize(mWindow, width, height);
	}

unsigned Window::width() const
	{
	int w;
	glfwGetWindowSize(mWindow, &w, 0);
	return w;
	}

unsigned Window::height() const
	{
	int h;
	glfwGetWindowSize(mWindow, 0, &h);
	return h;
	}

void Window::setVisible(bool visible)
	{
	if(visible)
		{
		glfwShowWindow(mWindow);
		}
	else
		{
		glfwHideWindow(mWindow);
		}
	}

bool Window::isOpen() const
	{
	return !glfwWindowShouldClose(mWindow);
	}

void Window::activate()
	{
	glfwMakeContextCurrent(mWindow);
	}

void Window::display()
	{
	glfwSwapBuffers(mWindow);
	}

}
