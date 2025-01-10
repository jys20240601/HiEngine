#pragma once
#include "Scene.h"
#include <memory>

class SceneManager 
{
public:
    enum class SceneType 
    {
        Title,
        Game,
        End
    };

    static SceneManager& GetInstance();
    void ChangeScene(SceneType sceneType);
    void Update();
    void Render(HDC hdc);

private:
    SceneManager();
    std::unique_ptr<Scene> currentScene;
};