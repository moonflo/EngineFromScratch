/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-05 16:33:42
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-07 10:23:49
 * @FilePath: \EngineFromScratch\m_test\ispcTest.cpp
 * @Description:
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#include <iostream>
#include "geommath_t.hpp"


using namespace std;
using namespace My;
extern void mandelbrot_ispc(float x0, float y0, float x1, float y1,
                            int32_t width, int32_t height,
                            int32_t maxIterations, int32_t* output);
void ppmWriter(const int image_width, const int image_height, const int* buf);

void vector_test() {
    Vector2f x = {55.3f, 22.1f};
    cout << "Vector2f: ";
    cout << x;

    Vector3f a = {1.0f, 2.0f, 3.0f};
    Vector3f b = {5.0f, 6.0f, 7.0f};

    cout << "vec 1: ";
    cout << a;
    cout << "vec 2: ";
    cout << b;

    Vector3f c;
    CrossProduct(c, a, b);
    cout << "Cross Product of vec 1 and vec 2: ";
    cout << c;

    float d;
    DotProduct(d, a, b);
    cout << "Dot Product of vec 1 and vec 2: ";
    cout << d << std::endl;

    MulByElement(c, a, b);
    cout << "Element Product of vec 1 and vec 2: ";
    cout << c;

    Vector4f e = {-3.0f, 3.0f, 6.0f, 1.0f};
    Vector4f f = {2.0f, 0.0f, -0.7f, 0.0f};
    cout << "vec 3: " << e;
    cout << "vec 4: " << f;

    Vector4f g = e + f;
    cout << "vec 3 + vec 4: " << g;
    g = e - f;
    cout << "vec 3 - vec 4: " << g;

    Normalize(g);
    cout << "normalized: " << g;
}

void matrix_test() {
    Matrix4X4f m1;
    BuildIdentityMatrix(m1);

    cout << "Idendity Matrix: ";
    cout << m1;

    float yaw = 0.2, pitch = 0.3, roll = 0.4;
    MatrixRotationYawPitchRoll(m1, yaw, pitch, roll);

    cout << "Matrix of yaw(" << yaw << ") pitch(" << pitch << ") roll(" << roll
         << "):";
    cout << m1;

    Matrix4X4f ry;
    float angle = PI / 2.0f;
    MatrixRotationY(ry, angle);

    cout << "Matrix of Rotation on Y(angle = " << angle << "):";
    cout << ry;

    Matrix4X4f rz;
    MatrixRotationZ(rz, angle);

    cout << "Matrix of Rotation on Z(angle = " << angle << "):";
    cout << rz;

    float x = 5.0f, y = 6.5f, z = -7.0f;
    Matrix4X4f translate;
    MatrixTranslation(translate, x, y, z);

    cout << "Matrix of Translation on X(" << x << ") Y(" << y << ") Z(" << z
         << "):";
    cout << translate;

    Vector3f v = {1.0f, 0.0f, 0.0f};

    Vector3f v1 = v;
    cout << "Vector : " << v1;
    cout << "Transform by Rotation Y Matrix:";
    cout << ry;
    TransformCoord(v1, ry);
    cout << "Now the vector becomes: " << v1;
    cout << std::endl;

    v1 = v;
    cout << "Vector : " << v1;
    cout << "Transform by Rotation Z Matrix:";
    cout << rz;
    TransformCoord(v1, rz);
    cout << "Now the vector becomes: " << v1;
    cout << std::endl;

    v1 = v;
    cout << "Vector : " << v1;
    cout << "Transform by Translation Matrix:";
    cout << translate;
    TransformCoord(v1, translate);
    cout << "Now the vector becomes: " << v1;
    cout << std::endl;

    Vector3f position = {0, 0, -5}, lookAt = {0, 0, 0}, up = {0, 1, 0};
    Matrix4X4f view;
    BuildViewMatrix(view, position, lookAt, up);
    cout << "View Matrix with position(" << position << ") lookAt(" << lookAt
         << ") up(" << up << "):";
    cout << view;

    float fov = PI / 2.0f, aspect = 16.0f / 9.0f, near = 1.0f, far = 100.0f;
    Matrix4X4f perspective;
    BuildPerspectiveFovLHMatrix(perspective, fov, aspect, near, far);
    cout << "Perspective Matrix with fov(" << fov << ") aspect(" << aspect
         << ") near ... far(" << near << " ... " << far << "):";
    cout << perspective;

    Matrix4X4f mvp = view * perspective;
    cout << "MVP:" << mvp;
}

int main() {
    unsigned int width = 768, height = 512;
    float x0 = -2., x1 = 1.;
    float y0 = -1., y1 = 1.;
    int maxIterations = 256;
    int* buf = new int[width * height];

    // ispc::mandelbrot_ispc(x0, y0, x1, y1, width, height, maxIterations, buf);

    // write output...
    // ppmWriter(width, height, buf);

    cout << std::fixed;

    vector_test();
    matrix_test();
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