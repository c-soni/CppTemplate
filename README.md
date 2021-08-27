# CMakeStarterProject
A template for a basic CMake setup

Commands for basic setup:

```
pip install conan # pip3 required
conan profile new default --detect
conan profile update settings.compiler.libcxx=libstdc++11 default

mkdir build && cd build
conan install ..

cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

clang-tidy ../src/*.cpp --fix

cmake --build .
./bin/app
```
