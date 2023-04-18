#include "GameObjectMgr.h"
#include "GameObject.h"

std::string GameObjectMgr::getErrorText()
{
    return error_text;
}

SDL_Rect GameObjectMgr::getGameObjectZone()
{
    return g_obj->getGameObjectZone();
}

SDL_Rect GameObjectMgr::getGameObjectRealZone()
{
    return g_obj->getGameObjectRealZone();
}

SDL_Point GameObjectMgr::getPosition()
{
    return { g_obj->getPositionBeginX(), g_obj->getPositionBeginY() };
}

void GameObjectMgr::setPosition(int x, int y)
{
    g_obj->setPosition(x, y);
}

void GameObjectMgr::setRealPosition(int x, int y)
{
    g_obj->setRealPosition(x, y);
}

int GameObjectMgr::getWidth()
{
    return g_obj->getWidth();
}

int GameObjectMgr::getHeight()
{
    return g_obj->getHeight();
}

void GameObjectMgr::setWidthHeight(int w, int h)
{
    g_obj->setWidthHeight(w, h);
}

void GameObjectMgr::setSpriteFilePath(std::string file_path)
{
    g_obj->setSpriteFilePath(file_path);
}