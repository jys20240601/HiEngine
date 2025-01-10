#include "Player.h"
#include "Input.h"

Player::Player(int x, int y, int width, int height)
    : GameObject(x, y, width, height) {}

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
}

void Player::Render(HDC hdc)
{
    Rectangle(hdc, GetPositionX(), GetPositionY(), GetPositionX() + GetWidth(), GetPositionY() + GetHeight());
}
