#include "Player.h"
#include "Input.h"

Player::Player(int x, int y, int width, int height)
    : GameObject(x, y, width, height) 
{
}

void Player::Fire() 
{
    mBullets.push_back(new Bullet(GetPositionX() + GetWidth() / 2 - 2, GetPositionY(), BULLET_SPEED));
}
void Player::Update()
{
    if (Input::IsKeyPressed(VK_LEFT))
    {
        SetPosition(GetPositionX() - 5, GetPositionY());
    }
    if (Input::IsKeyPressed(VK_RIGHT))
    {
        SetPosition(GetPositionX() + 5, GetPositionY());
    }
    if (Input::IsKeyPressed(VK_UP))
    {
        SetPosition(GetPositionX(), GetPositionY() - 5);
    }
    if (Input::IsKeyPressed(VK_DOWN))
    {
        SetPosition(GetPositionX(), GetPositionY() + 5);
    }

    if (Input::IsKeyPressed(VK_SPACE)) 
{
        Fire();
    }

    for (auto bullet : mBullets)
    {
        bullet->Update();
    }
}

void Player::Render(HDC hdc)
{
    GameObject::Render(hdc);

    for (auto bullet : mBullets)
    {
        bullet->Render(hdc);
    }
}
