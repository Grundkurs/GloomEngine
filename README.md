LeeEngine3
==========

TODO

How to use CMake
================
CMake allow us to generate Makefiles or project for various IDEs by describing the project in files named CMakeLists.txt

You can download CMake from [here](http://cmake.org/cmake/resources/software.html)
Download a version >= 2.8.11 (Which you may need to compile from source : ./configure --qt-gui && make && sudo make install)

To generate the project files :

```
cd Path/To/Lee/Engine
mkdir build && cd build
cmake ..
make
```

By default CMake will generate Makefiles, you can use to command line option -G "GENERATOR" to create other kind of projects. Use cmake --help to list possible options.
You only need to 
You can also use the CMake Qt based GUI : set Path/To/Lee/Engine as the source directory and Path/To/Lee/Engine/build as the build directory.

The build directory allow us not to create files in the source project tree. 

Some IDEs allow you to import CMake projects. This is the case for QtCreator (Open Project > Open the CMakeLists.txt at the project root).
They may create undesired files in the source project tree, you should add these files to the .gitignore file at the root of the project if that is the case.

The CMake files are setup to automatically compile all .cpp files in src folders. include folders are used for header files. To add files, just add them in those folders, and they will be found when compiling. Some IDEs will require you to re-run CMake in order to add the files to the project view, it should be doable from the IDE itself (e.g. Right click on the project > re-run CMake)
Support for non-c++ files will be added when needed, as support for installation.

To learn more about CMake, you can read [this](http://www.gamedev.net/page/resources/_/technical/general-programming/cross-platform-test-driven-development-environment-using-cmake-part-1-r2986) and look at this project's CMake files.


Documentation
=============
The makefile created by CMake contains a doc target used to build the documentation. Runing make doc will run doxygen and create documentation for the project in a doc directory.