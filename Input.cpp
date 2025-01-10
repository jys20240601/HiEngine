#include "Input.h"

bool Input::IsKeyPressed(int keyCode)
{
    return GetAsyncKeyState(keyCode) & 0x8000;
}
