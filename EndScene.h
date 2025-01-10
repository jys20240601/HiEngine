#pragma once
#include "Scene.h"

class EndScene : public Scene 
{
public:
    void Update() override;
    void Render(HDC hdc) override;
};