/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-10 11:48:42
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-15 18:49:23
 * @FilePath: \EngineFromScratch\Framework\Common\scene.hpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include "Interface.hpp"
#include "SceneNode.hpp"
#include "SceneObject.hpp"

namespace My {
class Scene {
   public:
    Scene(const char* scene_name) : SceneGraph(new BaseSceneNode(scene_name)) {}
    ~Scene() = default;

   public:
    std::shared_ptr<BaseSceneNode> SceneGraph;
    std::unordered_map<std::string, std::shared_ptr<SceneObjectCamera>> Cameras;
    std::unordered_map<std::string, std::shared_ptr<SceneObjectLight>> Lights;
    std::unordered_map<std::string, std::shared_ptr<SceneObjectMaterial>>
        Materials;
    std::unordered_map<std::string, std::shared_ptr<SceneObjectGeometry>>
        Geometries;

    const std::shared_ptr<SceneObjectCamera> GetCamera(std::string key) const;
    const std::shared_ptr<SceneObjectCamera> GetFirstCamera() const;
    const std::shared_ptr<SceneObjectCamera> GetNextCamera() const;

    const std::shared_ptr<SceneObjectLight> GetLight(std::string key) const;
    const std::shared_ptr<SceneObjectLight> GetFirstLight() const;
    const std::shared_ptr<SceneObjectLight> GetNextLight() const;

    const std::shared_ptr<SceneObjectMaterial> GetMaterial(
        std::string key) const;
    const std::shared_ptr<SceneObjectMaterial> GetFirstMaterial() const;
    const std::shared_ptr<SceneObjectMaterial> GetNextMaterial() const;

    const std::shared_ptr<SceneObjectGeometry> GetGeometry(
        std::string key) const;
    const std::shared_ptr<SceneObjectGeometry> GetFirstGeometry() const;
    const std::shared_ptr<SceneObjectGeometry> GetNextGeometry() const;
};
}  // namespace My
