git submodule update --init External\src\opengex
mkdir -p External\build\opengex
pushd External\build\opengex
del -rf *
cmake -DCMAKE_INSTALL_PREFIX=..\..\ -G "Visual Studio 17 2022" -Thost=x64 ..\..\src\opengex
cmake --build . --config debug --target install
popd
pause
