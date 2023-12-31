IF(${WIN32})
        SET(GEOMMATH_LIB_FILE ${CMAKE_CURRENT_BINARY_DIR}/GeomMath.lib)
        SET(ISPC_COMPILER ${PROJECT_SOURCE_DIR}/External/src/ispc-v1.20.0-windows/bin/ispc.exe)
        # SET(ISPC_COMPILER_PATH ${PROJECT_SOURCE_DIR}/External/ispc/Release/)
        if((TARGET_ARCH MATCHES "x86_64" OR TARGET_ARCH MATCHES "ia64") AND NOT OF_32BIT)
                MESSAGE( STATUS "[INFO] BUILD ISPC CODE WITH X86-64")
                SET(ISPC_OPTIONS --arch=x86-64)
                SET(LIBRARIAN_COMMAND lib /MACHINE:X64 /OUT:${GEOMMATH_LIB_FILE})
        else()
                MESSAGE( STATUS "[INFO] BUILD ISPC CODE WITH X86")
                SET(ISPC_OPTIONS --arch=x86)
                SET(LIBRARIAN_COMMAND lib /MACHINE:X86 /OUT:${GEOMMATH_LIB_FILE})
        endif()
ELSE()
        SET(GEOMMATH_LIB_FILE ${CMAKE_CURRENT_BINARY_DIR}/libGeomMath.a)
        SET(ISPC_COMPILER ispc)
        # SET(ISPC_COMPILER_PATH ${PROJECT_SOURCE_DIR}/External/ispc/)
        SET(ISPC_OPTIONS --arch=x86-64)
        SET(LIBRARIAN_COMMAND ar -crv -o ${GEOMMATH_LIB_FILE})
ENDIF(${WIN32})

SET(GEOMMATH_LIB_HEADER_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(ispc)

add_library(GeomMath STATIC IMPORTED GLOBAL)
add_dependencies(GeomMath GeomMathLib)

set_target_properties(GeomMath
        PROPERTIES
        IMPORTED_LOCATION ${GEOMMATH_LIB_FILE}
        INTERFACE_INCLUDE_DIRECTORIES ${GEOMMATH_LIB_HEADER_FOLDER}
        )

add_subdirectory(test)