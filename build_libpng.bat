git submodule update --init External/src/libpng
mkdir External\build\libpng
cd External\build\libpng
del -rf *
cmake -DCMAKE_PREFIX_PATH="../../Windows" -DCMAKE_INSTALL_PREFIX=..\..\windows -G "Visual Studio 17 2022" -Thost=x64 ..\..\src\libpng
cmake --build . --config debug --target install
pause
