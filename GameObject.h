#pragma once
#include <windows.h>

class GameObject
{
public:

	GameObject(int x, int y, int width, int height);
	virtual ~GameObject();


    virtual void Update();
    virtual void Render(HDC hdc);

    void SetPosition(int x, int y);
    void SetSize(int width, int height);

    int GetPositionX()const { return mX; }
    int GetPositionY()const { return mY; }

    int GetWidth()const { return mWidth; }
    int GetHeight()const { return mHeight; }

private:

    int mX, mY;
    int mWidth, mHeight;
};

