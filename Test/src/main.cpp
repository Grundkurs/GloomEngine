#include <iostream>

#include <LeeEngine3/Core/Factory.h>
#include <LeeEngine3/Renderer/Renderer.h>
#include <LeeEngine3/Renderer/Window.h>

int main(int argc, char** argv)
{
  std::cout << "Hello, world !" << std::endl;

  {
    using namespace lee;
    
    Renderer r;
    Window win(r);

    while(win.isOpen()){
      r.update();

      win.display();
    }
  }

  return 0;
}
