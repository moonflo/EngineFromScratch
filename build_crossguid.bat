git submodule update --init External/src/crossguid
mkdir External\build\crossguid
pushd External\build\crossguid
del -rf *
cmake -DCMAKE_INSTALL_PREFIX=..\..\Windows -G "Visual Studio 17 2022" -Thost=x64 ..\..\src\crossguid
cmake --build . --config debug --target install
popd
pause