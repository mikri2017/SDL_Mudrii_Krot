#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <SDL2/SDL.h>
#include "GameObjectMgr.h"

class Camera
{
private:
    SDL_Rect area;
    SDL_Point g_obj_mgr_pos;
    GameObjectMgr *g_obj_mgr;
    bool watch_g_obj_mgr;
public:
    Camera();
    ~Camera();
    int getPositionBeginX();
    int getPositionBeginY();
    void setPosition(int x, int y);
    void setWidthHeight(int w, int h);
    void updatePosition();
    void setGameObjectRelativePos(int x, int y);
    void setGameObjectWatchingMode(bool watch);
    void setGameObjectForWatch(GameObjectMgr *g_obj);
    SDL_Rect getGameObjectAreaInCam(GameObjectMgr *g_obj);
};

#endif // CAMERA_H_INCLUDED