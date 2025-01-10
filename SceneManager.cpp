#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "EndScene.h"

SceneManager& SceneManager::GetInstance() 
{
    static SceneManager instance;
    return instance;
}

SceneManager::SceneManager() : currentScene(std::make_unique<TitleScene>()) 
{
}

void SceneManager::ChangeScene(SceneType sceneType) 
{
    switch (sceneType) 
    {
    case SceneType::Title:
        currentScene = std::make_unique<TitleScene>();
        break;
    case SceneType::Game:
        currentScene = std::make_unique<GameScene>();
        break;
    case SceneType::End:
        currentScene = std::make_unique<EndScene>();
        break;
    }
}

void SceneManager::Update() 
{
    if (currentScene) 
    {
        currentScene->Update();
    }
}

void SceneManager::Render(HDC hdc) 
{
    if (currentScene) 
    {
        currentScene->Render(hdc);
    }
}