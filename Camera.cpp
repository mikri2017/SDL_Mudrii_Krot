#include "Camera.h"
#include "Debug.h"

Camera::Camera()
{
    // Задаем зону камеры на сцене
    area.x = 0;
    area.y = 0;
    area.w = 0;
    area.h = 0;

    // Задаем позицию игрового объекта
    // в кадре камеры
    g_obj_mgr_pos.x = 0;
    g_obj_mgr_pos.y = 0;

    watch_g_obj_mgr = false;
}

Camera::~Camera()
{
    debug() << "Camera end\n";
}

int Camera::getPositionBeginX()
{
    return area.x;
}

int Camera::getPositionBeginY()
{
    return area.y;
}

void Camera::setPosition(int x, int y)
{
        if (x < 0)
            x = 0;
        area.x = x;

        if (y < 0)
            y = 0;
        area.y = y;
}

void Camera::setWidthHeight(int w, int h)
{
    if (w < 0)
        w = 0;
    area.w = w;

    if (h < 0)
        h = 0;
    area.h = h;
}

void Camera::updatePosition()
{
    if (watch_g_obj_mgr)
    {
        // Меняем данные, если следим за
        // объектом - подстраиваемся под него
        SDL_Rect cur_g_obj_zone = g_obj_mgr->getGameObjectRealZone();
        debug() << "cur_g_obj_zone x: " << cur_g_obj_zone.x << " y: " << cur_g_obj_zone.y << "\n";
        
        area.x = cur_g_obj_zone.x - g_obj_mgr_pos.x;
        area.y = cur_g_obj_zone.y - g_obj_mgr_pos.y;

        // Проверяем выход за границы сцены
        if (area.x < 0)
            area.x = 0;
        if (area.y < 0)
            area.y = 0;
    }
}

void Camera::setGameObjectRelativePos(int x, int y)
{
    if (x < 0)
        x = 0;
    g_obj_mgr_pos.x = x;

    if (y < 0)
        y = 0;
    g_obj_mgr_pos.y = y;
}

void Camera::setGameObjectWatchingMode(bool watch)
{
    watch_g_obj_mgr = watch;
}

void Camera::setGameObjectForWatch(GameObjectMgr *g_obj)
{
    g_obj_mgr = g_obj;
}

SDL_Rect Camera::getGameObjectAreaInCam(GameObjectMgr *g_obj)
{
    SDL_Rect g_obj_in_cam_area = g_obj->getGameObjectRealZone();

    /*
    if (g_obj_in_cam_area.x + g_obj_in_cam_area.w > area.x + area.w)
        g_obj_in_cam_area.w -= area.x + area.w;
    if (g_obj_in_cam_area.y + g_obj_in_cam_area.h > area.y + area.h)
        g_obj_in_cam_area.h -= area.y + area.h;
    */

    g_obj_in_cam_area.x -= area.x;
    //g_obj_in_cam_area.y -= area.y;
    return g_obj_in_cam_area;
}