#include "GameObject.h"

GameObject::GameObject(int x, int y, int width, int height)
	:mX(x), mY(y), mWidth(width), mHeight(height)
{

}

GameObject::~GameObject()
{

}

void GameObject::Update()
{

}

void GameObject::Render(HDC hdc)
{
	Rectangle(hdc, mX, mY, mX + mWidth, mY + mHeight);
}

void GameObject::SetPosition(int x, int y)
{
	mX = x;
	mY = y;
}

void GameObject::SetSize(int width, int height)
{
	mWidth = width;
	mHeight = height;
}
