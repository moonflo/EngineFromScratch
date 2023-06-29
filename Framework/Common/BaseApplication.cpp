/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-06-26 15:16:01
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-06-28 18:21:52
 * @FilePath: \EngineFromScratch\Framework\Common\BaseApplication.cpp
 * @Description:
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#include "BaseApplication.hpp"
#include <iostream>

namespace My {

bool My::BaseApplication::m_bQuit = false;

My::BaseApplication::BaseApplication(GfxConfiguration& cfg) : m_Config(cfg) {}

// Parse command line, read configuration, initialize all sub modules
int My::BaseApplication::Initialize() {
    int result = 0;

    std::wcout << m_Config;

    return result;
}

// Finalize all sub modules and clean up all runtime temporary files.
void My::BaseApplication::Finalize() {}

// One cycle of the main loop
void My::BaseApplication::Tick() {}

bool My::BaseApplication::IsQuit() { return m_bQuit; }

}  // namespace My
