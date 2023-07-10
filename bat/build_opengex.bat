git submodule update --init ..\External\src\opengex
mkdir ..\External\build\opengex
pushd ..\External\build\opengex
del /f /s /q * >nul
cmake -DCMAKE_INSTALL_PREFIX=..\..\ -G "Visual Studio 17 2022" -Thost=x64 ..\..\src\opengex
cmake --build . --config debug --target install
popd

