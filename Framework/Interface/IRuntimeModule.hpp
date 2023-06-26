#pragma once
#include "Interface.hpp"

namespace My {
Interface IRuntimeModule {
   public:
    virtual ~IRuntimeModule(){};

    virtual int Initialize() = 0;  // For initialize module
    virtual void Finalize() = 0;   // For clear module

    virtual void Tick() = 0;  // Tick
};
}  // namespace My