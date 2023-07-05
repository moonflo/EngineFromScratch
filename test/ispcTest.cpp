/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-05 16:33:42
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-05 17:51:19
 * @FilePath: \EngineFromScratch\test\ispcTest.cpp
 * @Description:
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#include <iostream>
#include "ispcTest.h"

int main() {
    unsigned int width = 768, height = 512;
    float x0 = -2., x1 = 1.;
    float y0 = -1., y1 = 1.;
    int maxIterations = 256;
    int *buf = new int[width * height];

    mandelbrot_ispc(x0, y0, x1, y1, width, height, maxIterations, buf);

    // write output...
}