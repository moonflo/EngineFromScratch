@echo off
git submodule update --init External\src\opengex
mkdir -p External\build\opengex
pushd External\build\opengex
rm -rf *
cmake -DCMAKE_INSTALL_PREFIX=..\..\Windows -G "Visual Studio 17 2022 Win64" -Thost=x64 ..\..\src\opengex
cmake --build . --config debug --target install
popd

