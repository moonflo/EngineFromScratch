/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-08 09:31:25
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-08 10:00:32
 * @FilePath: \EngineFromScratch\Platform\Windows\OpenGLApplication.hpp
 * @Description:
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#pragma once
#include "WindowsApplication.hpp"
#include "AssetLoader.hpp"
#include "BMP.hpp"
#include "MemoryManager.hpp"
#include "utility.hpp"


namespace My {
class OpenGLApplication : public WindowsApplication {
   public:
    OpenGLApplication(GfxConfiguration& config) : WindowsApplication(config){};

    virtual int Initialize();
    virtual void Finalize();
    virtual void Tick();

   private:
    HGLRC m_RenderContext;

    // My costum
    Image m_Image[2];

   public:
    void initializeImageLoading();
};

}  // namespace My
