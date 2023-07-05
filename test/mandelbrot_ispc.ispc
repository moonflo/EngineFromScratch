
/* 1. export 指示该函数能够被其他的cpp文件读取，不仅仅是其他ispc文件；
** 2. 这种能与cpp文件沟通的函数中，它的参数是直接从cpp中读取的，不需要额外的
** 运行时对象；
** 3. uniform是一种类似全局变量的对象，和shader中的uniform中的定义是一样的
** 所有传入的参数都必须是uniform的,它的主要意义是界定了该值在每个线程中都是
** 不变的，是一种线程安全的值？；
*/
export void mandelbrot_ispc(
    uniform float x0, uniform float y0,
    uniform float x1, uniform float y1,
    uniform int width, uniform int height,
    uniform int maxIterations,
    uniform int output[]) 
{
    for (uniform int j = 0; j < height; j++) { // regular loop with uniform qualifier

        float dx = (x1 - x0) / width;
        float dy = (y1 - y0) / height;

        foreach (i = 0 ... width) 
        { 
            // width是和并行宽度有关的数值，控制一次循环中的并行数据数量， i 是一个和当前线程
            // i是一个个当前线程有关的数字，如16位的数据，一次8个线程，则i在不同线程中会是
            // (0,1,2,3,4,5,6,7)，和(8,9,10,11,12,13,14,15)
            float x = x0 + i * dx;
            float y = y0 + j * dy;
            int index = j * width + i;
            // 一次计算一行，同时算出每个线程像素点的坐标和index
            output[index] = mandel(x, y, maxIterations);
        }
    }
}

// 计算最大迭代次数内的迭代情况，如果发散了就break并且跳出，如果没有就迭代到最大值为止，返回是迭代次数
static inline int mandel(float c_re, float c_im, int count) {
    float z_re = c_re, z_im = c_im;
    int i;
    for (i = 0; i < count; ++i) {
        if (z_re * z_re + z_im * z_im > 4.)
            break;
        float new_re = z_re*z_re - z_im*z_im;
        float new_im = 2.f * z_re * z_im;
        z_re = c_re + new_re;
        z_im = c_im + new_im;
    }
    return i;
}