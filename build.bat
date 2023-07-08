mkdir build
pushd build
rm -rf *
cmake -G "Visual Studio 17 2022 Win64" -Thost=x64 ..
cmake --build . --config debug
popd

