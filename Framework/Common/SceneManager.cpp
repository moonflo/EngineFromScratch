/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-26 16:03:03
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-27 12:35:43
 * @FilePath: \EngineFromScratch\Framework\Common\SceneManager.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-26 16:03:03
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-26 16:18:44
 * @FilePath: \EngineFromScratch\Framework\Common\SceneManager.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include "SceneManager.hpp"
#include "AssetLoader.hpp"
#include "OGEX.hpp"

using namespace My;
using namespace std;

SceneManager::~SceneManager() {}

int SceneManager::Initialize() {
    int result = 0;

    m_pScene = make_shared<Scene>();
    return result;
}

void SceneManager::Finalize() {}

void SceneManager::Tick() {}

int SceneManager::LoadScene(const char* scene_file_name) {
    // now we only has ogex scene parser, call it directly
    if (LoadOgexScene(scene_file_name)) {
        m_pScene->LoadResource();
        m_bDirtyFlag = true;
        return 0;
    } else {
        return -1;
    }
}

void SceneManager::ResetScene() {
    m_bDirtyFlag = true;
}

bool SceneManager::LoadOgexScene(const char* ogex_scene_file_name) {
    string ogex_text =
        g_pAssetLoader->SyncOpenAndReadTextFileToString(ogex_scene_file_name);

    if (ogex_text.empty()) {
        return false;
    }

    OgexParser ogex_parser;
    m_pScene = ogex_parser.Parse(ogex_text);

    if (!m_pScene) {
        return false;
    }

    return true;
}

const Scene& SceneManager::GetSceneForRendering() {
    return *m_pScene;
}

bool SceneManager::IsSceneChanged() {
    return m_bDirtyFlag;
}

void SceneManager::NotifySceneIsRenderingQueued() {
    m_bDirtyFlag = false;
}