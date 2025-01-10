#pragma once
#include "Scene.h"

class GameScene : public Scene 
{
public:
    void Update() override;
    void Render(HDC hdc) override;
};