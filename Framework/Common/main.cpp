/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-10 11:48:42
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-12 20:59:52
 * @FilePath: \EngineFromScratch\Framework\Common\main.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include <chrono>
#include <cstdio>
#include <thread>
#include "BaseApplication.hpp"

using namespace My;

int main(int argc, char** argv) {
    int ret;

    if ((ret = g_pApp->Initialize()) != 0) {
        printf("App Initialize failed, will exit now.");
        return ret;
    } else {
        printf("App Initialize sucessfully.");
    }

    if ((ret = g_pMemoryManager->Initialize()) != 0) {
        printf("Memory Manager Initialize failed, will exit now.");
        return ret;
    } else {
        printf("Memory Manager Initialize sucessfully.");
    }

    if ((ret = g_pAssetLoader->Initialize()) != 0) {
        printf("Asset Loader Initialize failed, will exit now.");
        return ret;
    } else {
        printf("Asset Loader Initialize sucessfully.");
    }

    if ((ret = g_pSceneManager->Initialize()) != 0) {
        printf("Scene Manager Initialize failed, will exit now.");
        return ret;
    } else {
        printf("Scene Manager  Initialize sucessfully.");
    }

    g_pSceneManager->LoadScene("Scene/cube.ogex");

    if ((ret = g_pGraphicsManager->Initialize()) != 0) {
        printf("Graphics Manager Initialize failed, will exit now.");
        return ret;
    } else {
        printf("GraphicsInitialize sucessfully.");
    }

    while (!g_pApp->IsQuit()) {
        g_pApp->Tick();
        g_pMemoryManager->Tick();
        g_pAssetLoader->Tick();
        g_pSceneManager->Tick();
        g_pGraphicsManager->Tick();
        std::this_thread::sleep_for(std::chrono::microseconds(10000));
    }

    g_pGraphicsManager->Finalize();
    g_pSceneManager->Finalize();
    g_pAssetLoader->Finalize();
    g_pMemoryManager->Finalize();
    g_pApp->Finalize();

    return 0;
}
