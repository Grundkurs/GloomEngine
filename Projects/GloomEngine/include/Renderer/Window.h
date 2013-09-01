
#pragma once

//#include "Renderer.h"

#include <string>

struct GLFWwindow;

namespace gloom
{

class Renderer;

class Window
{
public:
	Window();
	//Window(Renderer& renderer);
	~Window();

	Window(Window const& other) = delete;
	Window& operator=(Window const& other) = delete;
	Window(Window && other) = delete;
	Window& operator=(Window && other) = delete;

	//Renderer& renderer();

	bool init( int width, int height );

	void activate();

	void display();

	void setTitle(std::string const& title);

	void setSize(unsigned width, unsigned height);

	unsigned width() const;
	unsigned height() const;

	void setVisible(bool visible);

	bool isOpen() const;

private:
	//Renderer& mRenderer;
	GLFWwindow * mpWindow;
};

}
