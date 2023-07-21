/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-17 16:21:31
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-20 16:56:18
 * @FilePath: \EngineFromScratch\Framework\Common\utility.hpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include <glad/glad.h>  // Include glad.h before any other OpenGL header
#include <windows.h>    // Include windows.h for system time functions
#include <iostream>
#include <string>  // Include string for parsing

namespace My {
template <class T>
inline void SafeRelease(T** ppInterfaceToRelease) {
    if (*ppInterfaceToRelease != nullptr) {
        (*ppInterfaceToRelease)->Release();

        (*ppInterfaceToRelease) = nullptr;
    }
}

// Get the current time as a float value in seconds using GetSystemTimeAsFileTime
float get_time_as_float() {
    FILETIME ft_now;
    GetSystemTimeAsFileTime(&ft_now);  // Get the current time as a FILETIME
    ULARGE_INTEGER uli_now;  // Convert the FILETIME to a 64-bit integer
    uli_now.LowPart = ft_now.dwLowDateTime;
    uli_now.HighPart = ft_now.dwHighDateTime;
    return uli_now.QuadPart / 10000.0f /
           1000.0f;  // Divide by 10,000 to get milliseconds, and by 1,000 to get seconds
}
}  // namespace My
