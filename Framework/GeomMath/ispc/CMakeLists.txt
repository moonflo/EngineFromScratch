set(FUNCTIONS CrossProduct DotProduct MulByElement Transpose Normalize
              Transform AddByElement SubByElement InverseMatrix4X4f DCT MatrixExchangeYandZ
        )

foreach(FUNC IN LISTS FUNCTIONS)
    add_custom_command(OUTPUT ${FUNC}.o
        # COMMAND ${CMAKE_COMMAND} -E env "PATH=${ISPC_COMPILER_PATH}" 
        COMMAND ${ISPC_COMPILER} ${ISPC_OPTIONS} -o ${FUNC}.o -h ${GEOMMATH_LIB_HEADER_FOLDER}/${FUNC}.h --target=host ${CMAKE_CURRENT_SOURCE_DIR}/${FUNC}.ispc
        MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/${FUNC}.ispc
        COMMENT "Building ${FUNC}"
        )

    list(APPEND OBJECTS ${FUNC}.o)

endforeach(FUNC)

add_custom_command(OUTPUT ${GEOMMATH_LIB_FILE}
        COMMAND ${LIBRARIAN_COMMAND} ${OBJECTS}
        COMMAND del -v ${OBJECTS}
        DEPENDS ${OBJECTS}
        )

add_custom_target(GeomMathLib
                   DEPENDS ${GEOMMATH_LIB_FILE}
)

