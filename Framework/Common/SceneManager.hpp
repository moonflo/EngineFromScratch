/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-17 21:48:22
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-17 23:42:40
 * @FilePath: \EngineFromScratch\Framework\Common\SceneManager.hpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#pragma once
#include "geommath.hpp"
#include "IRuntimeModule.hpp"
#include "SceneParser.hpp"

namespace My {
class SceneManager : implements IRuntimeModule {
   public:
    virtual ~SceneManager();

    virtual int Initialize();
    virtual void Finalize();

    virtual void Tick();

    int LoadScene(const char* scene_file_name);

    bool IsSceneChanged();
    const Scene& GetSceneForRendering();

   protected:
    bool LoadOgexScene(const char* ogex_scene_file_name);

   protected:
    std::unique_ptr<Scene> m_pScene;
    bool m_bDirtyFlag = false;
};

extern SceneManager* g_pSceneManager;
}  // namespace My