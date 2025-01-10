#include "Monster.h"

Monster::Monster(int x, int y, int width, int height)
    : GameObject(x, y, width, height), mSpeed(2)
{
    srand(static_cast<unsigned int>(time(0)));
    RandomizeDirection();
}

void Monster::Update()
{
    SetPosition(GetPositionX() + mDirection * mSpeed, GetPositionY());

    if (GetPositionX() <= 0 || GetPositionX() + GetWidth() >= 800)
    {
        RandomizeDirection();
    }
}

void Monster::Render(HDC hdc)
{
    GameObject::Render(hdc);
}

void Monster::RandomizeDirection()
{
    mDirection = (rand() % 2 == 0) ? 1 : -1;
}
