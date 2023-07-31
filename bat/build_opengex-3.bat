git submodule update --init ..\External\src\opengex-3
mkdir ..\External\build\opengex-3
pushd ..\External\build\opengex-3
del /f /s /q * >nul
cmake -DCMAKE_INSTALL_PREFIX=..\..\ -G "Visual Studio 17 2022" -Thost=x64 ..\..\src\opengex-3
cmake --build . --config debug --target install
popd

