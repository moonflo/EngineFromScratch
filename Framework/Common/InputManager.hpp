/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-17 23:30:25
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-17 23:31:13
 * @FilePath: \EngineFromScratch\Framework\Common\InputManager.hpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#pragma once
#include "IRuntimeModule.hpp"

namespace My {
class InputManager : implements IRuntimeModule {
   public:
    virtual int Initialize();
    virtual void Finalize();
    virtual void Tick();

    void UpArrowKeyDown();
    void UpArrowKeyUp();
    void DownArrowKeyDown();
    void DownArrowKeyUp();
    void LeftArrowKeyDown();
    void LeftArrowKeyUp();
    void RightArrowKeyDown();
    void RightArrowKeyUp();
};

extern InputManager* g_pInputManager;
}  // namespace My