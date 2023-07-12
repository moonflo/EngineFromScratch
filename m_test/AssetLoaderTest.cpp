/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-10 11:48:42
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-10 21:22:16
 * @FilePath: \EngineFromScratch\m_test\AssetLoaderTest.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include <iostream>
#include <string>
#include "AssetLoader.hpp"
#include "MemoryManager.hpp"

using namespace std;
using namespace My;

namespace My {
MemoryManager* g_pMemoryManager = new MemoryManager();
}

int main(int, char**) {
    g_pMemoryManager->Initialize();

    AssetLoader asset_loader;
    string shader_pgm =
        asset_loader.SyncOpenAndReadTextFileToString("Shaders/test.hs");

    cout << shader_pgm;

    g_pMemoryManager->Finalize();

    delete g_pMemoryManager;

    return 0;
}
