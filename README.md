# cube-timer
A rubik's cube timer gui built in C++ using SDL2

Currently only brings up a window and prints what should happen on keypress. 


## Build
You need [cmake](https://cmake.org/) and [vcpkg](https://github.com/microsoft/vcpkg) installed

```
git clone https://github.com/Ay-355/cube-timer
cd cube-timer
mkdir build
cd build
cmake .. "-DCMAKE_TOOLCHAIN_FILE=[vcpkg-root]/scripts/buildsystems/vcpkg.cmake"
cmake --build .
```
Your executable should be `./Debug/cube-timer`
