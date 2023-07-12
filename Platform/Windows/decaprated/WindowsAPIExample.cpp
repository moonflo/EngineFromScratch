#include <windows.h>
#include "glad/glad_wgl.h"

// Window procedure
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam,
                         LPARAM lParam) {
    switch (message) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    // Create a window class
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "OpenGLWindow";
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    // Register the window class
    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Failed to register the window class", "Error",
                   MB_OK | MB_ICONERROR);
        return 0;
    }

    // Create the window
    HWND hWnd = CreateWindowEx(
        0, "OpenGLWindow", "OpenGL RHI", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
        CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);

    if (hWnd == NULL) {
        MessageBox(NULL, "Failed to create the window", "Error",
                   MB_OK | MB_ICONERROR);
        return 0;
    }

    // Show the window
    ShowWindow(hWnd, nCmdShow);

    // Get the device context
    HDC hDC = GetDC(hWnd);

    // Choose a pixel format
    PIXELFORMATDESCRIPTOR pfd;
    ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;

    int iPixelFormat = ChoosePixelFormat(hDC, &pfd);

    if (iPixelFormat == 0) {
        MessageBox(NULL, "Failed to choose a pixel format", "Error",
                   MB_OK | MB_ICONERROR);
        return 0;
    }

    // Set the pixel format
    if (!SetPixelFormat(hDC, iPixelFormat, &pfd)) {
        MessageBox(NULL, "Failed to set the pixel format", "Error",
                   MB_OK | MB_ICONERROR);
        return 0;
    }

    // Create an OpenGL rendering context
    HGLRC hRC = wglCreateContext(hDC);

    if (hRC == NULL) {
        MessageBox(NULL, "Failed to create an OpenGL rendering context",
                   "Error", MB_OK | MB_ICONERROR);
        return 0;
    }

    // Make the rendering context current
    if (!wglMakeCurrent(hDC, hRC)) {
        MessageBox(NULL, "Failed to make the rendering context current",
                   "Error", MB_OK | MB_ICONERROR);
        return 0;
    }

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)wglGetProcAddress)) {
        MessageBox(NULL, "Failed to initialize GLAD", "Error",
                   MB_OK | MB_ICONERROR);
        return 0;
    }

    // Main loop
    MSG msg;
    BOOL bRet;
    while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0) {
        if (bRet == -1) {
            MessageBox(NULL, "GetMessage failed", "Error",
                       MB_OK | MB_ICONERROR);
            break;
        } else {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            // Clear the window with a color
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Swap buffers and draw
            SwapBuffers(hDC);
        }
    }

    // Delete the rendering context
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);

    // Release the device context
    ReleaseDC(hWnd, hDC);

    return (int)msg.wParam;
}
