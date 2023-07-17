/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-17 23:31:17
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-17 23:31:28
 * @FilePath: \EngineFromScratch\Framework\Common\InputManager.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include <iostream>
#include "InputManager.hpp"
#include "GraphicsManager.hpp"
#include "geommath.hpp"

using namespace My;
using namespace std;

int InputManager::Initialize() {
    return 0;
}

void InputManager::Finalize() {}

void InputManager::Tick() {}

void InputManager::UpArrowKeyDown() {
#ifdef DEBUG
    cerr << "[InputManager] Up Arrow Key Down!" << endl;
#endif
    g_pGraphicsManager->WorldRotateX(PI / 60.0f);
}

void InputManager::UpArrowKeyUp() {
#ifdef DEBUG
    cerr << "[InputManager] Up Arrow Key Up!" << endl;
#endif
}

void InputManager::DownArrowKeyDown() {
#ifdef DEBUG
    cerr << "[InputManager] Down Arrow Key Down!" << endl;
#endif
    g_pGraphicsManager->WorldRotateX(-PI / 60.0f);
}

void InputManager::DownArrowKeyUp() {
#ifdef DEBUG
    cerr << "[InputManager] Down Arrow Key Up!" << endl;
#endif
}

void InputManager::LeftArrowKeyDown() {
#ifdef DEBUG
    cerr << "[InputManager] Left Arrow Key Down!" << endl;
#endif
    g_pGraphicsManager->WorldRotateY(-PI / 60.0f);
}

void InputManager::LeftArrowKeyUp() {
#ifdef DEBUG
    cerr << "[InputManager] Left Arrow Key Up!" << endl;
#endif
}

void InputManager::RightArrowKeyDown() {
#ifdef DEBUG
    cerr << "[InputManager] Right Arrow Key Down!" << endl;
#endif
    g_pGraphicsManager->WorldRotateY(PI / 60.0f);
}

void InputManager::RightArrowKeyUp() {
#ifdef DEBUG
    cerr << "[InputManager] Right Arrow Key Up!" << endl;
#endif
}