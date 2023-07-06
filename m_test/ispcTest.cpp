/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-05 16:33:42
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-05 19:22:36
 * @FilePath: \EngineFromScratch\test\ispcTest.cpp
 * @Description:
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#include "ispcTest.h"
#include <iostream>


extern void mandelbrot_ispc(float x0, float y0, float x1, float y1,
                            int32_t width, int32_t height,
                            int32_t maxIterations, int32_t* output);
void ppmWriter(const int image_width, const int image_height, const int* buf);

int main() {
    unsigned int width = 768, height = 512;
    float x0 = -2., x1 = 1.;
    float y0 = -1., y1 = 1.;
    int maxIterations = 256;
    int* buf = new int[width * height];

    ispc::mandelbrot_ispc(x0, y0, x1, y1, width, height, maxIterations, buf);

    // write output...
    ppmWriter(width, height, buf);
    return 0;
}

void ppmWriter(const int image_width, const int image_height, const int* buf) {
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            int index = j * image_width + i;
            std::cout << buf[index] << ' ' << buf[index] << ' ' << buf[index]
                      << '\n';
        }
    }
}