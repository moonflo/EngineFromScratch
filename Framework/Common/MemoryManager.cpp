/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-06-28 14:48:24
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-06-28 15:48:55
 * @FilePath: \EngineFromScratch\Framework\Common\MemoryManager.cpp
 * @Description:
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#include "MemoryManager.hpp"
#include <malloc.h>

using namespace My;

namespace My {
static const uint32_t kBlockSizes[] = {
    // 4-increments
    4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76,
    80, 84, 88, 92, 96,

    // 32-increments
    128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448, 480, 512, 544, 576,
    608, 640,

    // 64-increments
    704, 768, 832, 896, 960, 1024};

static const uint32_t kPageSize = 8192;
static const uint32_t kAlignment = 4;

// number of elements in the block size array
static const uint32_t kNumBlockSizes =
    sizeof(kBlockSizes) / sizeof(kBlockSizes[0]);

// largest valid block size
static const uint32_t kMaxBlockSize = kBlockSizes[kNumBlockSizes - 1];
}  // namespace My

int My::MemoryManager::Initialize() {
    // one-time initialization
    static bool s_bInitialized = false;
    if (!s_bInitialized) {
        // initialize block size lookup table, this's a kind of hash map, 'cause
        // in here we can see that m_pBlockSizeLookup[0] ==
        // m_pBlockSizeLookup[4] = 0 and m_pBlockSizeLookup[12] = 2,
        // m_pBlockSizeLookup[8] = 1, anytime when we need a BlockSize = n, we
        // check the m_pBlockSizeLookup out and we could know the num's idnex in
        // kBlockSizes group.
        m_pBlockSizeLookup = new size_t[kMaxBlockSize + 1];
        size_t j = 0;
        for (size_t i = 0; i <= kMaxBlockSize; i++) {
            if (i > kBlockSizes[j]) ++j;
            m_pBlockSizeLookup[i] = j;
        }

        // initialize the allocators, for now we got 47 allocator and they have
        // difference block, same pageSize and same Alignment value, all
        // reserved in m_pAllocators, but not real assign so much address, only
        // set the param, and wait for allocat to do so.
        m_pAllocators = new Allocator[kNumBlockSizes];
        for (size_t i = 0; i < kNumBlockSizes; i++) {
            m_pAllocators[i].Reset(kBlockSizes[i], kPageSize, kAlignment);
        }
        s_bInitialized = true;
    }
    return 0;
}

void My::MemoryManager::Finalize() {
    delete[] m_pAllocators; // Why don't call allocator's free all?
    delete[] m_pBlockSizeLookup;
}

void My::MemoryManager::Tick() {}

/**
 * @description: find a allocator that satisfied blocksize require
 * @param {size_t} blockSize
 * @return {Allocator*} allocatorPointer if available, nullptr if not
 */
Allocator* My::MemoryManager::LookUpAllocator(size_t size) {
    // check eligibility for lookup
    if (size <= kMaxBlockSize)
        return m_pAllocators + m_pBlockSizeLookup[size];
    else
        return nullptr;
}

void* My::MemoryManager::Allocate(size_t size) {
    Allocator* pAlloc = LookUpAllocator(size);
    if (pAlloc)
        return pAlloc->Allocate();
    else
        return malloc(size);
}

void My::MemoryManager::Free(void* p, size_t size) {
    Allocator* pAlloc = LookUpAllocator(size);
    if (pAlloc)
        pAlloc->Free(p);
    else
        free(p);
}