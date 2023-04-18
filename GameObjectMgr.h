#ifndef GAMEOBJECTMGR_H_INCLUDED
#define GAMEOBJECTMGR_H_INCLUDED

#include "MainConstants.h"
#include <SDL2/SDL.h>
#include <string>

class GameObject;

class GameObjectMgr
{
protected:
    GameObject *g_obj;
    std::string error_text;
public:
    virtual ~GameObjectMgr() {};
    virtual std::string getErrorText();
    virtual bool init(SDL_Renderer *renderer) = 0;
    virtual void draw(SDL_Renderer *renderer) = 0;
    virtual SDL_Rect getGameObjectZone();
    virtual SDL_Rect getGameObjectRealZone();
    virtual SDL_Point getPosition();
    virtual void setPosition(int x, int y);
    virtual void setRealPosition(int x, int y);
    virtual int getWidth();
    virtual int getHeight();
    virtual void setWidthHeight(int w, int h);
    virtual void setSpriteFilePath(std::string file_path);
    virtual bool checkCollisionWithGameObject(GameObject *g_obj) = 0;
    virtual gameReaction process_mouse_motion(Sint32 x, Sint32 y) = 0;
    virtual gameReaction process_mouse_button_event(SDL_MouseButtonEvent m_btn_event) = 0;
    virtual gameReaction process_keyboard_keydown(SDL_Keycode keycode) = 0;
};

#endif // GAMEOBJECTMGR_H_INCLUDED