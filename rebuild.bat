echo [INFO] ----------Building project...
mkdir build
pushd build
del /f /s /q * >nul
cmake ..
popd
pause