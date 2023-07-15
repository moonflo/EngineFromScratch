/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-08 09:31:25
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-15 09:35:08
 * @FilePath: \EngineFromScratch\Framework\Common\Image.hpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#pragma once
#include "geommath.hpp"

namespace My {

typedef struct _Image {
    uint32_t Width;
    uint32_t Height;
    R8G8B8A8Unorm* data;
    uint32_t bitcount;
    uint32_t pitch;
    size_t data_size;
} Image;
std::ostream& operator<<(std::ostream& out, const Image& image);
}  // namespace My