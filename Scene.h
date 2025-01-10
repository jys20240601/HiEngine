#pragma once
#include <windows.h>

class Scene {
public:
    virtual ~Scene() {}
    virtual void Update() = 0;
    virtual void Render(HDC hdc) = 0;
};