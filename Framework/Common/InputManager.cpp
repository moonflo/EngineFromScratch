/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-17 23:31:17
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-31 19:36:27
 * @FilePath: \EngineFromScratch\Framework\Common\InputManager.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include <iostream>

#include "InputManager.hpp"

#include "GraphicsManager.hpp"
#include "SceneManager.hpp"
#include "geommath.hpp"
// #include "utility.hpp"
#include "CameraMove.hpp"

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

void InputManager::WKeyUp() {

    cerr << "[InputManager] W Key Up!" << endl;
}
void InputManager::AKeyUp() {

    cerr << "[InputManager] A Key Up!" << endl;
}
void InputManager::SKeyUp() {

    cerr << "[InputManager] S Key Up!" << endl;
}
void InputManager::DKeyUp() {

    cerr << "[InputManager] D Key Up!" << endl;
}

void InputManager::WKeyDown() {
    g_pGraphicsManager->CameraMovement(My::Camera_Movement::FORWARD);
    cerr << "[InputManager] W Key Down!" << endl;
    cerr << "Now Translation is:"
         << g_pGraphicsManager->m_cameraState.getTranslate() << endl;
    cerr << "Now Position is:" << g_pGraphicsManager->m_cameraState.Position
         << endl;
}

void InputManager::AKeyDown() {
    g_pGraphicsManager->CameraMovement(My::Camera_Movement::LEFT);
    cerr << "[InputManager] A Key Down!" << endl;
    cerr << "Now Translation is:"
         << g_pGraphicsManager->m_cameraState.getTranslate() << endl;
    cerr << "Now Position is:" << g_pGraphicsManager->m_cameraState.Position
         << endl;
}
void InputManager::SKeyDown() {
    g_pGraphicsManager->CameraMovement(My::Camera_Movement::BACKWARD);
    cerr << "[InputManager] S Key Down!" << endl;
    cerr << "Now Translation is:"
         << g_pGraphicsManager->m_cameraState.getTranslate() << endl;
    cerr << "Now Position is:" << g_pGraphicsManager->m_cameraState.Position
         << endl;
}
void InputManager::DKeyDown() {
    g_pGraphicsManager->CameraMovement(My::Camera_Movement::RIGHT);
    cerr << "[InputManager] D Key Down!" << endl;
    cerr << "Now Translation is:"
         << g_pGraphicsManager->m_cameraState.getTranslate() << endl;
    cerr << "Now Position is:" << g_pGraphicsManager->m_cameraState.Position
         << endl;
}
void InputManager::ResetKeyDown() {
#ifdef DEBUG
    cerr << "[InputManager] Reset Key Down!" << endl;
#endif
    g_pSceneManager->ResetScene();
}

void InputManager::ResetKeyUp() {
#ifdef DEBUG
    cerr << "[InputManager] Reset Key Up!" << endl;
#endif
}
void InputManager::MouseMove(int xposIn, int yposIn){};
void InputManager::MouseScroll(int zDelta, int xposIn, int yposIn){};