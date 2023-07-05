//
// C:/codingEnv/ispc-v1.20.0-windows/examples/cpu/build/rt/rt_ispc_sse2.h
// (Header automatically generated by the ispc compiler.)
// DO NOT EDIT THIS FILE.
//

#pragma once
#include <stdint.h>



#ifdef __cplusplus
namespace ispc { /* namespace */
#endif // __cplusplus

#ifndef __ISPC_ALIGN__
#if defined(__clang__) || !defined(_MSC_VER)
// Clang, GCC, ICC
#define __ISPC_ALIGN__(s) __attribute__((aligned(s)))
#define __ISPC_ALIGNED_STRUCT__(s) struct __ISPC_ALIGN__(s)
#else
// Visual Studio
#define __ISPC_ALIGN__(s) __declspec(align(s))
#define __ISPC_ALIGNED_STRUCT__(s) __ISPC_ALIGN__(s) struct
#endif
#endif

#ifndef __ISPC_STRUCT_LinearBVHNode__
#define __ISPC_STRUCT_LinearBVHNode__
struct LinearBVHNode {
    float bounds[2][3];
    uint32_t offset;
    uint8_t nPrimitives;
    uint8_t splitAxis;
    uint16_t pad;
};
#endif

#ifndef __ISPC_STRUCT_Triangle__
#define __ISPC_STRUCT_Triangle__
struct Triangle {
    float p[3][4];
    int32_t id;
    int32_t pad[3];
};
#endif


///////////////////////////////////////////////////////////////////////////
// Functions exported from ispc code
///////////////////////////////////////////////////////////////////////////
#if defined(__cplusplus) && (! defined(__ISPC_NO_EXTERN_C) || !__ISPC_NO_EXTERN_C )
extern "C" {
#endif // __cplusplus
    extern void raytrace_ispc(int32_t width, int32_t height, int32_t baseWidth, int32_t baseHeight, const float raster2camera[][4], const float camera2world[][4], float * image, int32_t * id, const struct LinearBVHNode * nodes, const struct Triangle * triangles);
    extern void raytrace_ispc_tasks(int32_t width, int32_t height, int32_t baseWidth, int32_t baseHeight, const float raster2camera[][4], const float camera2world[][4], float * image, int32_t * id, const struct LinearBVHNode * nodes, const struct Triangle * triangles);
#if defined(__cplusplus) && (! defined(__ISPC_NO_EXTERN_C) || !__ISPC_NO_EXTERN_C )
} /* end extern C */
#endif // __cplusplus


#ifdef __cplusplus
} /* namespace */
#endif // __cplusplus
