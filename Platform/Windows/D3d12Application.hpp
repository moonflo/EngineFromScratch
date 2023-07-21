/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-18 19:31:34
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-18 19:31:39
 * @FilePath: \EngineFromScratch\Platform\Windows\D3d12Application.hpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#pragma once
#include "WindowsApplication.hpp"

namespace My {
class D3d12Application : public WindowsApplication {
   public:
    using WindowsApplication::WindowsApplication;
    void Tick();
};
}  // namespace My