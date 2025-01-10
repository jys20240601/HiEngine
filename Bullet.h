#pragma once
#include "GameObject.h"

class Bullet : public GameObject 

{
public:
    Bullet(int x, int y, int speed);
    void Update() override;
    void Render(HDC hdc) override;

private:
    int mSpeed;
};