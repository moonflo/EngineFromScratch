/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-19 16:42:47
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-21 18:27:05
 * @FilePath: \EngineFromScratch\Framework\Common\CameraMove.hpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#pragma once
#include <vector>
#include "geommath.hpp"

namespace My {
enum Camera_Movement { FORWARD, BACKWARD, LEFT, RIGHT };

// Default camera values
const float YAW = 0.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class CameraState {
   public:
    // camera Attributes
    Vector3f Position;
    Vector3f Front;
    Vector3f Up;
    Vector3f Right;
    Vector3f WorldUp;
    // euler Angles
    float Yaw;
    float Pitch;
    // camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    // constructor with vectors
    CameraState(Vector3f position = Vector3f(0.0f, 0.0f, 0.0f),
                Vector3f up = Vector3f(0.0f, 1.0f, 0.0f), float yaw = YAW,
                float pitch = PITCH)
        : Front(Vector3f(0.0f, 0.0f, -1.0f)),
          MovementSpeed(SPEED),
          MouseSensitivity(SENSITIVITY),
          Zoom(ZOOM) {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    };
    // constructor with scalar values
    CameraState(float posX, float posY, float posZ, float upX, float upY,
                float upZ, float yaw, float pitch)
        : Front(Vector3f(0.0f, 0.0f, -1.0f)),
          MovementSpeed(SPEED),
          MouseSensitivity(SENSITIVITY),
          Zoom(ZOOM) {
        Position = Vector3f(posX, posY, posZ);
        WorldUp = Vector3f(upX, upY, upZ);
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    };

    void clear(){};

    Matrix4X4f getTranslate() {
        Matrix4X4f result;
        MatrixTranslation(result, Position.x, Position.y, Position.z);
        return result;
    };
    Matrix4X4f getRotation() {
        Matrix4X4f result;
        MatrixRotationYawPitchRoll(result, Yaw, Pitch, 0);
        return result;
    };

   private:
    double angle_to_radian(double degree) { return degree * (PI / 180.0); };
    double radian_to_angle(double rad) { return rad * (180.0 / PI); };
    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors() {
        // calculate the new Front vector
        Vector3f front;
        front.x = cos(angle_to_radian(Yaw)) * cos(angle_to_radian(Pitch));
        front.y = sin(angle_to_radian(Pitch));
        front.z = sin(angle_to_radian(Yaw)) * cos(angle_to_radian(Pitch));
        Normalize(front);
        Front = front;
        CrossProduct(Front, WorldUp, Right);
        Normalize(Right);
        CrossProduct(Right, Front, Up);
        Normalize(Up);
    };
};

}  // namespace My
