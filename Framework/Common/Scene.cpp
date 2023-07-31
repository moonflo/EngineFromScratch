/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-26 16:03:03
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-26 16:36:17
 * @FilePath: \EngineFromScratch\Framework\Common\Scene.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include "Scene.hpp"

using namespace My;
using namespace std;

const shared_ptr<SceneObjectCamera> Scene::GetCamera(
    const std::string& key) const {
    auto i = Cameras.find(key);
    if (i == Cameras.end())
        return nullptr;
    else
        return i->second;
}

const shared_ptr<SceneObjectLight> Scene::GetLight(
    const std::string& key) const {
    auto i = Lights.find(key);
    if (i == Lights.end())
        return nullptr;
    else
        return i->second;
}

const shared_ptr<SceneObjectGeometry> Scene::GetGeometry(
    const std::string& key) const {
    auto i = Geometries.find(key);
    if (i == Geometries.end())
        return nullptr;
    else
        return i->second;
}

const shared_ptr<SceneObjectMaterial> Scene::GetMaterial(
    const std::string& key) const {
    auto i = Materials.find(key);
    if (i == Materials.end())
        return m_pDefaultMaterial;
    else
        return i->second;
}

const shared_ptr<SceneObjectMaterial> Scene::GetFirstMaterial() const {
    return (Materials.empty() ? nullptr : Materials.cbegin()->second);
}

const shared_ptr<SceneGeometryNode> Scene::GetFirstGeometryNode() const {
    return (GeometryNodes.empty() ? nullptr : GeometryNodes.cbegin()->second);
}

const shared_ptr<SceneLightNode> Scene::GetFirstLightNode() const {
    return (LightNodes.empty() ? nullptr : LightNodes.cbegin()->second);
}

const shared_ptr<SceneCameraNode> Scene::GetFirstCameraNode() const {
    return (CameraNodes.empty() ? nullptr : CameraNodes.cbegin()->second);
}

void Scene::LoadResource() {
    for (auto material : Materials) {
       // std::cout << "[Scene : INFO] Loading material: \n" << *material << std::endl;
        material.second->LoadTextures();
    }
}