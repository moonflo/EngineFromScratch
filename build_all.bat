echo [INFO] ----------Building external libraries...
pushd bat

echo [INFO] ----------Building zlib...
call build_zlib.bat

echo [INFO] ----------Building opengex...
call build_opengex.bat

echo [INFO] ----------Building crossguid...
call build_crossguid.bat

echo [INFO] ----------Building libpng...
call build_libpng.bat
popd

pushd External\src\glad
echo [INFO] ----------Building glad...
call glad_generate.bat
popd

echo [INFO] ----------Building project...
mkdir build
pushd build
del /f /s /q * >nul
cmake ..
popd
pause