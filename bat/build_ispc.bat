git submodule update --init ..\External\src\ispc
mkdir ..\External\build\ispc
pushd ..\External\build\ispc
del /f /s /q * >nul
cmake -DCMAKE_INSTALL_PREFIX=..\..\Windows -G "Visual Studio 17 2022" -Thost=x64 ..\..\src\ispc
cmake --build . --config debug --target install
popd
pause