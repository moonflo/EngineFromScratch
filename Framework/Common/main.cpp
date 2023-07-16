/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-13 22:32:28
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-16 10:59:37
 * @FilePath: \EngineFromScratch\Framework\Common\main.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include <cstdio>
#include <chrono>
#include <thread>
#include "BaseApplication.hpp"

using namespace My;
using namespace std;

int main(int argc, char** argv) {
    int ret;

    if ((ret = g_pApp->Initialize()) != 0) {
        printf("App Initialize failed, will exit now.");
        return ret;
    }

    if ((ret = g_pMemoryManager->Initialize()) != 0) {
        printf("Memory Manager Initialize failed, will exit now.");
        return ret;
    }

    if ((ret = g_pAssetLoader->Initialize()) != 0) {
        printf("Asset Loader Initialize failed, will exit now.");
        return ret;
    }

    if ((ret = g_pSceneManager->Initialize()) != 0) {
        printf("Scene Manager Initialize failed, will exit now.");
        return ret;
    }

    string scene_file_name = "Scene/cube.ogex";
    if (argc > 1) {
        scene_file_name = argv[1];
    }

    if ((ret = g_pSceneManager->LoadScene(scene_file_name.c_str())) != 0) {
        printf("Unable to load scene: %s\n", scene_file_name.c_str());
        return ret;
    }

    if ((ret = g_pGraphicsManager->Initialize()) != 0) {
        printf("Graphics Manager Initialize failed, will exit now.");
        return ret;
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