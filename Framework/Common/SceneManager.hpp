/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-13 22:32:28
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-15 14:07:17
 * @FilePath: \EngineFromScratch\Framework\Common\SceneManager.hpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#pragma once
#include "IRuntimeModule.hpp"
#include "SceneParser.hpp"
#include "geommath.hpp"

namespace My {
class SceneManager : implements IRuntimeModule {
   public:
    virtual ~SceneManager();

    virtual int Initialize();
    virtual void Finalize();

    virtual void Tick();

    void LoadScene(const char* scene_file_name);

    const Scene& GetSceneForRendering();

   protected:
    void LoadOgexScene(const char* ogex_scene_file_name);

   protected:
    std::shared_ptr<Scene> m_pScene;
};

extern SceneManager* g_pSceneManager;
}  // namespace My
