#ifndef MAINHEROMGR_H_INCLUDED
#define MAINHEROMGR_H_INCLUDED

#include "GameObjectMgr.h"

class MainHero;

class MainHeroMgr : public GameObjectMgr
{
private:
    int move_step;
public:
    MainHeroMgr();
    ~MainHeroMgr();
    bool init(SDL_Renderer *renderer);
    void draw(SDL_Renderer *renderer);
    bool checkCollisionWithGameObject(GameObject *g_obj);
    gameReaction process_mouse_motion(Sint32 x, Sint32 y);
    gameReaction process_mouse_button_event(SDL_MouseButtonEvent m_btn_event);
    gameReaction process_keyboard_keydown(SDL_Keycode keycode);
    void setMoveStep(int step);
};

#endif // MAINHEROMGR_H_INCLUDED