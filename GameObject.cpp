#include "GameObject.h"

std::string GameObject::getErrorText()
{
    return error_text;
}

SDL_Rect GameObject::getGameObjectZone()
{
    return g_obj_zone;
}

SDL_Rect GameObject::getGameObjectRealZone()
{
    return g_obj_real_zone;
}

int GameObject::getPositionBeginX()
{
    return g_obj_zone.x;
}

int GameObject::getPositionBeginY()
{
    return g_obj_zone.y;
}

int GameObject::getRealPositionBeginX()
{
    return g_obj_real_zone.x;
}

int GameObject::getRealPositionBeginY()
{
    return g_obj_real_zone.y;
}

void GameObject::setPosition(int x, int y)
{
    g_obj_zone.x = x;
    g_obj_zone.y = y;
}

void GameObject::setRealPosition(int x, int y)
{
    g_obj_real_zone.x = x;
    g_obj_real_zone.y = y;
}

int GameObject::getWidth()
{
    return g_obj_real_zone.w;
}

int GameObject::getHeight()
{
    return g_obj_real_zone.h;
}

void GameObject::setWidthHeight(int w, int h)
{
    if (w < 0)
        w = 0;
    g_obj_zone.w = w;
    g_obj_real_zone.w = w;

    if (h < 0)
        h = 0;
    g_obj_zone.h = h;
    g_obj_real_zone.h = h;
}

void GameObject::setSpriteFilePath(std::string file_path)
{
    sprite_file_path = file_path;
}