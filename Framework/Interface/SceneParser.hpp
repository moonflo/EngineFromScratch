/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-10 11:48:42
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-16 10:47:54
 * @FilePath: \EngineFromScratch\Framework\Interface\SceneParser.hpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#pragma once
#include "Scene.hpp"
#include "Interface.hpp"


namespace My {
Interface SceneParser {
   public:
    virtual std::unique_ptr<Scene> Parse(const std::string& buf) = 0;
};
}  // namespace My