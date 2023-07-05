/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-05 17:47:45
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-05 17:49:51
 * @FilePath: \EngineFromScratch\test\ispcTest.h
 * @Description:
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus
extern void mandelbrot_ispc(float x0, float y0, float x1, float y1, int width,
                            int height, int maxIterations, int output[]);
#ifdef __cplusplus
}
#endif  // __cplusplus
