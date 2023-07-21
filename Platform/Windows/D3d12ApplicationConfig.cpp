/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-18 19:30:42
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-18 19:30:48
 * @FilePath: \EngineFromScratch\Platform\D3d12ApplicationConfig.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include <tchar.h>
#include "D3d12Application.hpp"
#include "D3d/D3d12GraphicsManager.hpp"

namespace My {
GfxConfiguration config(8, 8, 8, 8, 32, 0, 0, 960, 540,
                        _T("Game Engine From Scratch (Windows D3d12)"));
IApplication* g_pApp = static_cast<IApplication*>(new D3d12Application(config));
GraphicsManager* g_pGraphicsManager =
    static_cast<GraphicsManager*>(new D3d12GraphicsManager);
MemoryManager* g_pMemoryManager =
    static_cast<MemoryManager*>(new MemoryManager);
AssetLoader* g_pAssetLoader = static_cast<AssetLoader*>(new AssetLoader);
SceneManager* g_pSceneManager = static_cast<SceneManager*>(new SceneManager);
InputManager* g_pInputManager = static_cast<InputManager*>(new InputManager);
}  // namespace My