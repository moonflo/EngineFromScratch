# Install script for directory: C:/codingEnv/ispc-v1.20.0-windows/examples/cpu

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/ispc_examples")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/aobench/cmake_install.cmake")
  include("C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/aobench_instrumented/cmake_install.cmake")
  include("C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/deferred/cmake_install.cmake")
  include("C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/gmres/cmake_install.cmake")
  include("C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/mandelbrot/cmake_install.cmake")
  include("C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/mandelbrot_tasks/cmake_install.cmake")
  include("C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/noise/cmake_install.cmake")
  include("C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/options/cmake_install.cmake")
  include("C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/perfbench/cmake_install.cmake")
  include("C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/rt/cmake_install.cmake")
  include("C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/sgemm/cmake_install.cmake")
  include("C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/simple/cmake_install.cmake")
  include("C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/sort/cmake_install.cmake")
  include("C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/stencil/cmake_install.cmake")
  include("C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/volume_rendering/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
