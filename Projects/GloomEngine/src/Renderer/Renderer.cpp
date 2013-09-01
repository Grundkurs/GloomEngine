#include "include/Renderer/Renderer.h"

/*

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>

namespace lee{

Renderer::Renderer(){
  glfwSetErrorCallback([](int error, char const* description){
	//TODO replace with proper logging code
	std::clog << "GLFW : " << description << std::endl;
  });

  if (!glfwInit()){
	throw std::runtime_error("glfwInit failed");
  }else{
	std::clog << "glewInit ok" << std::endl;
  }

  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE);
#ifdef LEE_DEBUG
  glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
  mBaseContext = glfwCreateWindow(800, 600, "baseContext", 0, 0);
  glfwWindowHint(GLFW_VISIBLE, GL_TRUE);

  if(!mBaseContext){
	throw std::runtime_error("glfwCreateWindow failed");
  }
}

Renderer::~Renderer(){
  glfwDestroyWindow(mBaseContext);
  glfwTerminate();
}

GLFWwindow* Renderer::baseContext(){
  return mBaseContext;
}

void Renderer::update(){
  glfwPollEvents();
}

}

*/
