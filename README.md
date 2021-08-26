# CMakeStarterProject
A template for a basic CMake setup

Commands for basic setup:

```
conan profile new default --detect
conan profile update settings.compiler.libcxx=libstdc++11 default

mkdir build && cd build
conan install ..

cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build .
./bin/app
```
