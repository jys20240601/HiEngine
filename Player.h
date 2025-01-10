#pragma once
#include "GameObject.h"
class Player :public GameObject
{
public:

    Player(int x, int y, int width, int height);
    void Update() override;
    void Render(HDC hdc) override;

};

