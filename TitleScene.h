#pragma once
#include "Scene.h"

class TitleScene : public Scene 
{
public:
    void Update() override;
    void Render(HDC hdc) override;
};