#pragma once
#include <new>
#include "Allocator.hpp"
#include "IRuntimeModule.hpp"

namespace My {
class MemoryManager : implements IRuntimeModule {
   public:
    /**
     * @description: Using "placement new" to contruct a T-class and pass the
     * parameters to its constructor function. Meanwhile call the Allocate func
     * to assign a space to storage this class and pass the pointer to
     * "placement new", so that we could be able to manipulate the address by
     * our own allocate.
     * @param {Arguments...} parameters
     * @param {T} refer the type of class-T we wanna construct
     * @return {T*} pointer op class-T
     */
    template <typename T, typename... Arguments>
    T* New(Arguments... parameters) {
        return new (Allocate(sizeof(T))) T(parameters...);
    }

    template <typename T>
    void Delete(T* p) {
        reinterpret_cast<T*>(p)->~T();
        Free(p, sizeof(T));
    }

   public:
    virtual ~MemoryManager() {}

    virtual int Initialize();
    virtual void Finalize();
    virtual void Tick();

    void* Allocate(size_t size);
    void* Allocate(size_t size, size_t alignment);
    void Free(void* p, size_t size);

   private:
    // A hash-type group for block_size&allocatorIndex in m_pAllocators
    static size_t* m_pBlockSizeLookup;
    // A group of pointer to management all allocators
    static Allocator* m_pAllocators;

   private:
    // Check if such a size is available in allocator groups, if so return its
    // address
    static Allocator* LookUpAllocator(size_t size);
};
}  // namespace My