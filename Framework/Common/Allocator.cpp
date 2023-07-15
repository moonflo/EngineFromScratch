/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-06-28 10:48:53
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-13 13:54:56
 * @FilePath: \EngineFromScratch\Framework\Common\Allocator.cpp
 * @Description:
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#include "Allocator.hpp"
#include <cassert>
#include <cstring>

#ifndef ALIGN
#define ALIGN(x, a) (((x) + ((a)-1)) & ~((a)-1))
#endif

using namespace My;

My::Allocator::Allocator()
    : m_pPageList(nullptr),
      m_pFreeList(nullptr),
      m_szDataSize(0),
      m_szPageSize(0),
      m_szAlignmentSize(0),
      m_szBlockSize(0),
      m_nBlocksPerPage(0) {}

My::Allocator::Allocator(size_t data_size, size_t page_size, size_t alignment)
    : m_pPageList(nullptr), m_pFreeList(nullptr) {
    Reset(data_size, page_size, alignment);
}

My::Allocator::~Allocator() { FreeAll(); }

/**
 * @description: According to the aligment the block size that does not satisfy
 * the corresponding power can be expanded to the corresponding size. This
 * function first records the data size and page size, then expands the block
 * size, and records the redundant space caused when the size is expanded, and
 * finally calculates how many blocks a page has according to the block size.
 * Note that this often results in excess space that is less than one block
 * size.
 * @param {size_t}datasize is the size of a data
 * @param {size_t}pagesize is the size of a page you want todesign
 * @param {size_t}aligment is an integer power of 2.
 * @return: {void}
 */
void My::Allocator::Reset(size_t data_size, size_t page_size,
                          size_t alignment) {
    FreeAll();

    m_szDataSize = data_size;
    m_szPageSize = page_size;

    size_t minimal_size = (sizeof(BlockHeader) > m_szDataSize)
                              ? sizeof(BlockHeader)
                              : m_szDataSize;
    // this ALIGN magic only works when alignment is 2^n, which should general
    // be the case because most CPU/GPU also requires the aligment be in 2^n but
    // still we use a assert to guarantee it
#if defined(_DEBUG)
    // ((alignment & (alignment - 1))) == 0 can used to check if aligment is 2^n
    assert(alignment > 0 && ((alignment & (alignment - 1))) == 0);
#endif
    m_szBlockSize = ALIGN(minimal_size, alignment);

    m_szAlignmentSize = m_szBlockSize - minimal_size;

    m_nBlocksPerPage = (m_szPageSize - sizeof(PageHeader)) / m_szBlockSize;
}

/**
 * @description: alloc and free blocks
 * @return {*}
 */
void* My::Allocator::Allocate() {
    if (!m_pFreeList) {
        // allocate a new page, Allocate the size of the space according to the
        // initial pagesize, and then convert its address (that is, the address
        // of the first element) to pageHeader
        PageHeader* pNewPage =
            reinterpret_cast<PageHeader*>(new uint8_t[m_szPageSize]);
        ++m_nPages;
        m_nBlocks += m_nBlocksPerPage;
        m_nFreeBlocks += m_nBlocksPerPage;

#if defined(_DEBUG)
        FillFreePage(pNewPage);
#endif

        if (m_pPageList) {
            pNewPage->pNext = m_pPageList;
        } else {
            pNewPage->pNext = nullptr;
        }

        m_pPageList = pNewPage;

        BlockHeader* pBlock = pNewPage->Blocks();
        // link each block in the page
        for (uint32_t i = 0; i < m_nBlocksPerPage - 1; i++) {
            pBlock->pNext = NextBlock(pBlock);
            pBlock = NextBlock(pBlock);
        }
        pBlock->pNext = nullptr;

        m_pFreeList = pNewPage->Blocks();
    }

    BlockHeader* freeBlock = m_pFreeList;
    m_pFreeList = m_pFreeList->pNext;
    --m_nFreeBlocks;

#if defined(_DEBUG)
    FillAllocatedBlock(freeBlock);
#endif

    return reinterpret_cast<void*>(freeBlock);
}

/**
 * @description:
 * @param {void*} p
 * @return {*}
 */
void My::Allocator::Free(void* p) {
    BlockHeader* block = reinterpret_cast<BlockHeader*>(p);

#if defined(_DEBUG)
    FillFreeBlock(block);
#endif

    block->pNext = m_pFreeList;
    m_pFreeList = block;
    ++m_nFreeBlocks;
}

void My::Allocator::FreeAll() {
    PageHeader* pPage = m_pPageList;
    while (pPage) {
        PageHeader* _p = pPage;
        pPage = pPage->pNext;

        delete[] reinterpret_cast<uint8_t*>(_p);
    }

    m_pPageList = nullptr;
    m_pFreeList = nullptr;

    m_nPages = 0;
    m_nBlocks = 0;
    m_nFreeBlocks = 0;
}

#if defined(_DEBUG)
void My::Allocator::FillFreePage(PageHeader* pPage) {
    // page header
    pPage->pNext = nullptr;

    // blocks
    BlockHeader* pBlock = pPage->Blocks();
    for (uint32_t i = 0; i < m_nBlocksPerPage; i++) {
        FillFreeBlock(pBlock);
        pBlock = NextBlock(pBlock);
    }
}

void My::Allocator::FillFreeBlock(BlockHeader* pBlock) {
    // block header + data
    std::memset(pBlock, PATTERN_FREE, m_szBlockSize - m_szAlignmentSize);

    // alignment
    std::memset(
        reinterpret_cast<uint8_t*>(pBlock) + m_szBlockSize - m_szAlignmentSize,
        PATTERN_ALIGN, m_szAlignmentSize);
}

void My::Allocator::FillAllocatedBlock(BlockHeader* pBlock) {
    // block header + data
    std::memset(pBlock, PATTERN_ALLOC, m_szBlockSize - m_szAlignmentSize);

    // alignment
    std::memset(
        reinterpret_cast<uint8_t*>(pBlock) + m_szBlockSize - m_szAlignmentSize,
        PATTERN_ALIGN, m_szAlignmentSize);
}
#endif
My::BlockHeader* My::Allocator::NextBlock(BlockHeader* pBlock) {
    return reinterpret_cast<BlockHeader*>(reinterpret_cast<uint8_t*>(pBlock) +
                                          m_szBlockSize);
}
