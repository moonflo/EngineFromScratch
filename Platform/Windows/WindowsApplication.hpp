/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-13 22:32:28
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-17 23:35:36
 * @FilePath: \EngineFromScratch\Platform\Windows\WindowsApplication.hpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#pragma once
// include the basic windows header file
#include <windows.h>
#include <windowsx.h>
#include "BaseApplication.hpp"

namespace My {
class WindowsApplication : public BaseApplication {
   public:
    WindowsApplication(GfxConfiguration& config) : BaseApplication(config){};

    virtual int Initialize();
    virtual void Finalize();
    // One cycle of the main loop
    virtual void Tick();

    HWND GetMainWindow() { return m_hWnd; };

   protected:
    void CreateMainWindow();

   private:
    // the WindowProc function prototype
    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam,
                                       LPARAM lParam);

   protected:
    HWND m_hWnd;
};
}  // namespace My