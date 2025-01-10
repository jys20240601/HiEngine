#pragma once
#include "GameObject.h"
#include <cstdlib>
#include <ctime>

class Monster : public GameObject
{
public:
    Monster(int x, int y, int width, int height);
    void Update() override;
    void Render(HDC hdc) override;

private:
    int mDirection;
    int mSpeed;

    void RandomizeDirection();
};