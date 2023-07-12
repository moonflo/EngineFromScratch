#pragma once
#include "IRuntimeModule.hpp"
#include "SceneParser.hpp"
#include "geommath.hpp"

namespace My {
class SceneManager : implements IRuntimeModule {
   public:
    virtual ~SceneManager();

    virtual int Initialize();
    virtual void Finalize();

    virtual void Tick();

    void LoadScene(const char* scene_file_name);

    const Scene& GetSceneForRendering();

   protected:
    void LoadOgexScene(const char* ogex_scene_file_name);

   protected:
    std::unique_ptr<Scene> m_pScene;
};

extern SceneManager* g_pSceneManager;
}  // namespace My
