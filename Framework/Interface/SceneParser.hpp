/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-08 19:50:43
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-08 19:50:48
 * @FilePath: \EngineFromScratch\Framework\Interface\SceneParser.hpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#pragma once
#include <memory>
#include <string>
#include "Interface.hpp"
#include "SceneNode.hpp"

namespace My {
Interface SceneParser {
   public:
    virtual std::unique_ptr<BaseSceneNode> Parse(const std::string& buf) = 0;
};
}  // namespace My