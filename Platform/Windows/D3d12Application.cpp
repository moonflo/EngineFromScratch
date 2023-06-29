/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-06-28 19:10:47
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-06-29 10:59:51
 * @FilePath: \EngineFromScratch\Platform\Windows\D3d12Application.cpp
 * @Description:
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#include <tchar.h>
#include "D3d/D3d12GraphicsManager.hpp"
#include "MemoryManager.hpp"
#include "WindowsApplication.hpp"

using namespace My;

namespace My {
GfxConfiguration config(8, 8, 8, 8, 32, 0, 0, 960, 540,
                        _T("Game Engine From Scratch (Windows)"));
IApplication* g_pApp =
    static_cast<IApplication*>(new WindowsApplication(config));
GraphicsManager* g_pGraphicsManager =
    static_cast<GraphicsManager*>(new D3d12GraphicsManager);
MemoryManager* g_pMemoryManager =
    static_cast<MemoryManager*>(new MemoryManager);
}  // namespace My
