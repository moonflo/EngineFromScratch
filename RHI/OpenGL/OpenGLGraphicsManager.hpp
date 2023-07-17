/*
 * @Author: Xuepu Zeng 2307665474zxp@gmail.com
 * @Date: 2023-07-13 22:32:28
 * @LastEditors: Xuepu Zeng 2307665474zxp@gmail.com
 * @LastEditTime: 2023-07-17 22:35:21
 * @FilePath: \EngineFromScratch\RHI\OpenGL\OpenGLGraphicsManager.hpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#pragma once
#include "GraphicsManager.hpp"
#include "geommath.hpp"
#include <unordered_map>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include "glad/glad.h"
#include "SceneObject.hpp"

namespace My {
class OpenGLGraphicsManager : public GraphicsManager {
   public:
    virtual int Initialize();
    virtual void Finalize();

    virtual void Tick();

    virtual void Clear();

    virtual void Draw();

   private:
    bool SetPerBatchShaderParameters(const char* paramName,
                                     const Matrix4X4f& param);
    bool SetPerBatchShaderParameters(const char* paramName,
                                     const Vector3f& param);
    bool SetPerBatchShaderParameters(const char* paramName, const float param);
    bool SetPerBatchShaderParameters(const char* paramName,
                                     const GLint texture_index);
    bool SetPerFrameShaderParameters();

    void InitializeBuffers();
    void RenderBuffers();
    void CalculateCameraMatrix();
    void CalculateLights();
    bool InitializeShader(const char* vsFilename, const char* fsFilename);

   private:
    unsigned int m_vertexShader;
    unsigned int m_fragmentShader;
    unsigned int m_shaderProgram;
    std::map<std::string, GLint> m_TextureIndex;

    struct DrawFrameContext {
        Matrix4X4f m_worldMatrix;
        Matrix4X4f m_viewMatrix;
        Matrix4X4f m_projectionMatrix;
        Vector3f m_lightPosition;
        Vector4f m_lightColor;
    };

    struct DrawBatchContext {
        GLuint vao;
        GLenum mode;
        GLenum type;
        GLsizei count;
        std::shared_ptr<Matrix4X4f> transform;
        std::shared_ptr<SceneObjectMaterial> material;
    };

    DrawFrameContext m_DrawFrameContext;
    std::vector<DrawBatchContext> m_DrawBatchContext;
    std::vector<GLuint> m_Buffers;
    std::vector<GLuint> m_Textures;
};

}  // namespace My