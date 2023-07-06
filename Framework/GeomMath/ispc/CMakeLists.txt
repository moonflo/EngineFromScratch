set(FUNCTIONS CrossProduct DotProduct MulByElement Transpose Normalize
              Transform AddByElement SubByElement
        )
foreach(FUNC IN LISTS FUNCTIONS)
    add_custom_command(OUTPUT ${FUNC}.o
        COMMAND ${CMAKE_COMMAND} -E echo "Pre-build command"
        COMMAND ${ISPC_COMPILER} ${ISPC_OPTIONS} -o ${FUNC}.o -I .. -h ${GEOMMATH_LIB_HEADER_FOLDER}/${FUNC}.h --target=host ${CMAKE_CURRENT_SOURCE_DIR}/${FUNC}.ispc
        MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/${FUNC}.ispc
        COMMENT "Building ${FUNC}"
        )

    list(APPEND OBJECTS ${FUNC}.o)

endforeach(FUNC)

add_custom_command(OUTPUT ${GEOMMATH_LIB_FILE}
        COMMAND ${LIBRARIAN_COMMAND} ${OBJECTS}
        COMMAND rm -v ${OBJECTS}
        DEPENDS ${OBJECTS}
        )

add_custom_target(GeomMathLib
                   DEPENDS ${GEOMMATH_LIB_FILE}
        )

# ispc --arch=x86-64 --target=host -o CrossProduct.o -I ./ -h ./include/CrossProduct.h ./ispc/CrossProduct.ispc
# ispc --arch=x86-64 --target=host -o DotProduct.o -I ./ -h ./include/DotProduct.h ./ispc/DotProduct.ispc
# ispc --arch=x86-64 --target=host -o MulByElement.o -I ./ -h ./include/MulByElement.h ./ispc/MulByElement.ispc
# ispc --arch=x86-64 --target=host -o Transpose.o -I ./ -h ./include/Transpose.h ./ispc/Transpose.ispc
# ispc --arch=x86-64 --target=host -o Normalize.o -I ./ -h ./include/Normalize.h ./ispc/Normalize.ispc
# ispc --arch=x86-64 --target=host -o Transform.o -I ./ -h ./include/Transform.h ./ispc/Transform.ispc
# ispc --arch=x86-64 --target=host -o AddByElement.o -I ./ -h ./include/AddByElement.h ./ispc/AddByElement.ispc
# ispc --arch=x86-64 --target=host -o SubByElement.o -I ./ -h ./include/SubByElement.h ./ispc/SubByElement.ispc
