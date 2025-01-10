#include "Bullet.h"

Bullet::Bullet(int x, int y, int speed)
    : GameObject(x, y, 5, 10), mSpeed(speed)
{
}

void Bullet::Update()
{
    SetPosition(GetPositionX()+mSpeed, GetPositionY());
}

void Bullet::Render(HDC hdc)
{
    Rectangle(hdc, GetPositionX(), GetPositionY(), GetPositionX() + GetWidth(), GetPositionY() + GetHeight());
}