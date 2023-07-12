/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-06-27 16:32:36
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-12 15:29:11
 * @FilePath: \EngineFromScratch\Framework\Common\GraphicsManager.hpp
 * @Description:
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#pragma once
#include "IRuntimeModule.hpp"
#include "Image.hpp"


namespace My {
class GraphicsManager : implements IRuntimeModule {
   public:
    virtual ~GraphicsManager() {}

    virtual int Initialize();
    virtual void Finalize();

    virtual void Tick();

    virtual void Clear();
    virtual void Draw();
};

extern GraphicsManager* g_pGraphicsManager;
}  // namespace My
