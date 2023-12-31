/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-13 22:32:28
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-17 22:39:11
 * @FilePath: \EngineFromScratch\Framework\Common\AssetLoader.hpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
#include "IRuntimeModule.hpp"
#include "Buffer.hpp"

namespace My {
class AssetLoader : public IRuntimeModule {
   public:
    virtual ~AssetLoader(){};

    virtual int Initialize();
    virtual void Finalize();

    virtual void Tick();

    typedef void* AssetFilePtr;

    enum AssetOpenMode {
        MY_OPEN_TEXT = 0,    /// Open In Text Mode
        MY_OPEN_BINARY = 1,  /// Open In Binary Mode
    };

    enum AssetSeekBase {
        MY_SEEK_SET = 0,  /// SEEK_SET
        MY_SEEK_CUR = 1,  /// SEEK_CUR
        MY_SEEK_END = 2   /// SEEK_END
    };

    bool AddSearchPath(const char* path);

    bool RemoveSearchPath(const char* path);

    bool FileExists(const char* filePath);

    AssetFilePtr OpenFile(const char* name, AssetOpenMode mode);

    Buffer SyncOpenAndReadText(const char* filePath);

    Buffer SyncOpenAndReadBinary(const char* filePath);

    size_t SyncRead(const AssetFilePtr& fp, Buffer& buf);

    void CloseFile(AssetFilePtr& fp);

    size_t GetSize(const AssetFilePtr& fp);

    int32_t Seek(AssetFilePtr fp, long offset, AssetSeekBase where);

    inline std::string SyncOpenAndReadTextFileToString(const char* fileName) {
        std::string result;
        Buffer buffer = SyncOpenAndReadText(fileName);
        char* content = reinterpret_cast<char*>(buffer.GetData());

        if (content) {
            result = std::string(std::move(content));
        }
        std::cout << "[AssetLoader : INFO] Loaded file: " << fileName << std::endl;
        return result;
    }

   private:
    std::vector<std::string> m_strSearchPath;
};

extern AssetLoader* g_pAssetLoader;
}  // namespace My