/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-12 20:54:06
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-17 18:07:24
 * @FilePath: \EngineFromScratch\m_test\SceneLoadingTest.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include <iostream>
#include <string>
#include "AssetLoader.hpp"
#include "MemoryManager.hpp"
#include "SceneManager.hpp"

using namespace My;
using namespace std;

namespace My {
MemoryManager* g_pMemoryManager = new MemoryManager();
AssetLoader* g_pAssetLoader = new AssetLoader();
SceneManager* g_pSceneManager = new SceneManager();
}  // namespace My

template <typename T>
static ostream& operator<<(ostream& out,
                           unordered_map<string, shared_ptr<T>> map) {
    for (auto p : map) {
        out << *p.second << endl;
    }

    return out;
}

int main(int, char**) {
    g_pMemoryManager->Initialize();
    g_pSceneManager->Initialize();
    g_pAssetLoader->Initialize();

    g_pSceneManager->LoadScene("Scene/cube.ogex");
    auto& scene = g_pSceneManager->GetSceneForRendering();

    cout << "Dump of Cameras" << endl;
    cout << "---------------------------" << endl;
    weak_ptr<SceneObjectCamera> pCamera = scene.GetFirstCamera();
    while (auto pObj = pCamera.lock()) {
        cout << *pObj << endl;
        pCamera = scene.GetNextCamera();
    }

    cout << "Dump of Lights" << endl;
    cout << "---------------------------" << endl;
    weak_ptr<SceneObjectLight> pLight = scene.GetFirstLight();
    while (auto pObj = pLight.lock()) {
        cout << *pObj << endl;
        pLight = scene.GetNextLight();
    }

    cout << "Dump of Geometries" << endl;
    cout << "---------------------------" << endl;
    weak_ptr<SceneObjectGeometry> pGeometry = scene.GetFirstGeometry();
    while (auto pObj = pGeometry.lock()) {
        cout << *pObj << endl;
        pGeometry = scene.GetNextGeometry();
    }

    cout << "Dump of Materials" << endl;
    cout << "---------------------------" << endl;
    weak_ptr<SceneObjectMaterial> pMaterial = scene.GetFirstMaterial();
    while (auto pObj = pMaterial.lock()) {
        cout << *pObj << endl;
        pMaterial = scene.GetNextMaterial();
    }

    g_pSceneManager->Finalize();
    g_pAssetLoader->Finalize();
    g_pMemoryManager->Finalize();

    delete g_pSceneManager;
    delete g_pAssetLoader;
    delete g_pMemoryManager;

    return 0;
}
