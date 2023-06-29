/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-06-28 19:10:47
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-06-29 11:31:35
 * @FilePath: \EngineFromScratch\Platform\Windows\OpenGLApplication.cpp
 * @Description:
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#include "OpenGLApplication.hpp"
#include <errhandlingapi.h>
#include <stdio.h>
#include <tchar.h>
#include "MemoryManager.hpp"
#include "OpenGL/OpenGLGraphicsManager.hpp"
#include "glad/glad_wgl.h"

using namespace My;

namespace My {
GfxConfiguration config(8, 8, 8, 8, 32, 0, 0, 960, 540,
                        _T("Game Engine From Scratch (Windows)"));
IApplication* g_pApp =
    static_cast<IApplication*>(new OpenGLApplication(config));
GraphicsManager* g_pGraphicsManager =
    static_cast<GraphicsManager*>(new OpenGLGraphicsManager);
MemoryManager* g_pMemoryManager =
    static_cast<MemoryManager*>(new MemoryManager);

}  // namespace My

int My::OpenGLApplication::Initialize() {
    int result;
    result = WindowsApplication::Initialize();
    if (result) {
        printf("[ERROR] OpenGLApp: Windows Application initialize failed.\n");
    } else {
        printf(
            "[INFO] OpenGLApp: Windows Application initialize sucessfully.\n");
        PIXELFORMATDESCRIPTOR pfd;
        memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
        pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
        pfd.nVersion = 1;
        pfd.dwFlags =
            PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = m_Config.redBits + m_Config.greenBits +
                         m_Config.blueBits + m_Config.alphaBits;
        pfd.cDepthBits = m_Config.depthBits;
        pfd.iLayerType = PFD_MAIN_PLANE;

        HWND hWnd =
            reinterpret_cast<WindowsApplication*>(g_pApp)->GetMainWindow();
        HDC hDC = GetDC(hWnd);
        // Set a temporary default pixel format.
        int nPixelFormat = ChoosePixelFormat(hDC, &pfd);
        if (nPixelFormat == 0) return -1;

        // Examining Pixel format
        DescribePixelFormat(hDC, nPixelFormat, sizeof(pfd), &pfd);
        printf("Pixel format: %d\n", nPixelFormat);
        printf("Color bits: %d\n", pfd.cColorBits);
        printf("Depth bits: %d\n", pfd.cDepthBits);
        printf("Stencil bits: %d\n", pfd.cStencilBits);
        printf("Flags: %x\n", pfd.dwFlags);

        result = SetPixelFormat(hDC, nPixelFormat, &pfd);
        if (result != 1) {
            auto errorCode = GetLastError();
            printf(
                "[ERROR] OpenGLApp: SetPixelFormat failed with exit code "
                "%lu.\n",
                errorCode);
            return -1;
        }

        // Create a temporary rendering context.
        m_RenderContext = wglCreateContext(hDC);
        if (!m_RenderContext) {
            printf("[ERROR] OpenGLApp: wglCreateContext failed.\n");
            return -1;
        }

        // Set the temporary rendering context as the current rendering context
        // for this window.
        result = wglMakeCurrent(hDC, m_RenderContext);
        if (result != 1) {
            printf("[ERROR] OpenGLApp: wglMakeCurrent failed.\n");
            return -1;
        }

        if (!gladLoadWGL(hDC)) {
            printf("WGL initialize failed!\n");
            result = -1;
        } else {
            result = 0;
            printf("WGL initialize finished!\n");
        }
    }

    return result;
}

void My::OpenGLApplication::Finalize() {
    if (m_RenderContext) {
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(m_RenderContext);
        m_RenderContext = 0;
    }

    WindowsApplication::Finalize();
}

void My::OpenGLApplication::Tick() { WindowsApplication::Tick(); }
