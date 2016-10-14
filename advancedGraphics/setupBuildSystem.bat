@echo == Moving to *build* directory - creating if needed ...

mkdir build

cd build

conan install .. --build missing

set PATH="C:\Program Files\CMake\bin";%PATH%

cmake .. -G "Visual Studio 14 Win64"

cmake --build . --config Release

cd ..

pause