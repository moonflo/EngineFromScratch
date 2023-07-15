/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-10 11:48:42
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-15 14:08:22
 * @FilePath: \EngineFromScratch\Framework\Interface\SceneParser.hpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#pragma once
#include "Scene.hpp"

namespace My {
Interface SceneParser {
   public:
    virtual std::shared_ptr<Scene> Parse(const std::string& buf) = 0;
};
}  // namespace My