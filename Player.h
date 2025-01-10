#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include <vector>

class Player :public GameObject
{
public:

    Player(int x, int y, int width, int height);
    void Update() override;
    void Render(HDC hdc) override;

    void Fire();    //발사
    std::vector<Bullet*> mBullets;

private:
    const int BULLET_SPEED = 10; // 총알 속도

};

