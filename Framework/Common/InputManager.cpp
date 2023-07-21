/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-17 23:31:17
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-19 15:41:33
 * @FilePath: \EngineFromScratch\Framework\Common\InputManager.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include "InputManager.hpp"
#include <iostream>
#include "GraphicsManager.hpp"
#include "geommath.hpp"
#include "utility.hpp"

using namespace My;
using namespace std;

int InputManager::Initialize() {
    currentTime = get_time_as_float();
    lastTime = get_time_as_float();
    return 0;
}

void InputManager::Finalize() {}

void InputManager::Tick() {
    currentTime = get_time_as_float();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;
}

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

void InputManager::WKeyUp() {
#ifdef DEBUG
    cerr << "[InputManager] W Key Up!" << endl;
#endif
}
void InputManager::AKeyUp() {
#ifdef DEBUG
    cerr << "[InputManager] A Key Up!" << endl;
#endif
}
void InputManager::SKeyUp() {
#ifdef DEBUG
    cerr << "[InputManager] S Key Up!" << endl;
#endif
}
void InputManager::DKeyUp() {
#ifdef DEBUG
    cerr << "[InputManager] D Key Up!" << endl;
#endif
}

void InputManager::WKeyDown() {
#ifdef DEBUG
    cerr << "[InputManager] W Key Up!" << endl;
#endif
}

void InputManager::WKeyDown() {}
void MouseScroll(int zDelta, int xposIn, int yposIn) {}