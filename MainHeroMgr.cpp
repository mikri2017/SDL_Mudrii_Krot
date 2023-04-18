#include "MainHeroMgr.h"
#include "MainHero.h"
#include "Debug.h"
#include <iostream>

MainHeroMgr::MainHeroMgr()
{
    g_obj = new MainHero();
    g_obj->setTextureRowAndFrame(1, 0);

    move_step = 0;
}

MainHeroMgr::~MainHeroMgr()
{
    //delete gr_power_mgr;
    delete g_obj;
    debug() << "MainHeroMgr end\n";
}

bool MainHeroMgr::init(SDL_Renderer *renderer)
{
    if (!g_obj->init(renderer))
    {
        error_text = g_obj->getErrorText();
        return false;
    } else return true;
}

void MainHeroMgr::draw(SDL_Renderer *renderer)
{
    g_obj->draw(renderer);
}

bool MainHeroMgr::checkCollisionWithGameObject(GameObject *g_obj)
{
    return false;
}

gameReaction MainHeroMgr::process_mouse_motion(Sint32 x, Sint32 y)
{
    return gameReaction::gr_ignore;
}

gameReaction MainHeroMgr::process_mouse_button_event(SDL_MouseButtonEvent m_btn_event)
{
    return gameReaction::gr_ignore;
}

gameReaction MainHeroMgr::process_keyboard_keydown(SDL_Keycode keycode)
{
    if (keycode == SDLK_LEFT)
    {
        if (g_obj->getRealPositionBeginX() - move_step >= 0)
        {
            g_obj->setRealPosition(g_obj->getRealPositionBeginX() - move_step, g_obj->getRealPositionBeginY());
        }
        //gr_power_mgr->setAngle(-90-(90-58));
        g_obj->setTextureRowAndFrame(2, 0);
    }
    else if (keycode == SDLK_RIGHT)
    {
        g_obj->setRealPosition(g_obj->getRealPositionBeginX() + move_step, g_obj->getRealPositionBeginY());
        //gr_power_mgr->setAngle(-58);
        g_obj->setTextureRowAndFrame(1, 0);
    }
    else if (keycode == SDLK_SPACE)
    {
        //gr_power_mgr->setBeginPoint(g_obj->getRealPositionBeginX(), g_obj->getRealPositionBeginY());
    }

    return gameReaction::gr_ignore;
}

void MainHeroMgr::setMoveStep(int step)
{
    if (step < 0)
        step = 0;
    move_step = step;
}