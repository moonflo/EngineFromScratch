#pragma once
#include "Buffer.hpp"
#include "Image.hpp"
#include "Interface.hpp"

namespace My {
// Get an image from a buffer.
Interface ImageParser {
   public:
    virtual Image Parse(const Buffer& buf) = 0;
};
}  // namespace My