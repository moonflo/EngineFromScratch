/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-19 15:18:39
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-21 18:25:41
 * @FilePath: \EngineFromScratch\Framework\Common\GraphicsManager.hpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#pragma once
#include "IRuntimeModule.hpp"
#include "Image.hpp"
#include "geommath.hpp"
#include "CameraMove.hpp"

namespace My {

class GraphicsManager : implements IRuntimeModule {
   public:
    virtual ~GraphicsManager() {}

    virtual int Initialize();
    virtual void Finalize();

    virtual void Tick();

    virtual void Clear();
    virtual void Draw();

    void WorldRotateX(float radians);
    void WorldRotateY(float radians);
    void CameraMovement(Camera_Movement direction);
    void CameraAppliy() {
        Matrix4X4f trans = m_cameraState.getTranslate();
        Matrix4X4f rotat = m_cameraState.getRotation();
        m_DrawFrameContext.m_viewMatrix =
            m_DrawFrameContext.m_viewMatrix * trans;
        //         m_DrawFrameContext.m_viewMatrix =
        // m_DrawFrameContext.m_viewMatrix * trans * rotat;
    };
    CameraState m_cameraState;

   protected:
    bool SetPerFrameShaderParameters();
    bool SetPerBatchShaderParameters(const char* paramName,
                                     const Matrix4X4f& param);
    bool SetPerBatchShaderParameters(const char* paramName,
                                     const Vector3f& param);
    bool SetPerBatchShaderParameters(const char* paramName, const float param);
    bool SetPerBatchShaderParameters(const char* paramName, const int param);

    void InitConstants();
    bool InitializeShader(const char* vsFilename, const char* fsFilename);
    void InitializeBuffers();
    void CalculateCameraMatrix();
    void CalculateLights();
    void RenderBuffers();

   protected:
    struct DrawFrameContext {
        Matrix4X4f m_worldMatrix;
        Matrix4X4f m_viewMatrix;
        Matrix4X4f m_projectionMatrix;
        Vector3f m_lightPosition;
        Vector4f m_lightColor;
    };

    DrawFrameContext m_DrawFrameContext;
};

extern GraphicsManager* g_pGraphicsManager;
}  // namespace My