/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-06-26 15:16:10
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-06-28 18:21:44
 * @FilePath: \EngineFromScratch\Framework\Common\BaseApplication.hpp
 * @Description:
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#pragma once
#include "GfxConfiguration.h"
#include "IApplication.hpp"

namespace My {
class BaseApplication : implements IApplication {
   public:
    BaseApplication(GfxConfiguration& cfg);
    virtual int Initialize();
    virtual void Finalize();
    // One cycle of the main loop
    virtual void Tick();

    virtual bool IsQuit();

    inline GfxConfiguration& GetConfiguration() { return m_Config; };

   protected:
    // Flag if need quit the main loop of the application
    static bool m_bQuit;
    GfxConfiguration m_Config;

   private:
    // hide the default construct to enforce a configuration
    BaseApplication(){};
};
}  // namespace My