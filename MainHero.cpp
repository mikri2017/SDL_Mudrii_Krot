#include "MainHero.h"
#include "TextureMgr.h"
#include "Debug.h"
#include <SDL2/SDL_image.h>

MainHero::MainHero()
{
    g_obj_zone = { 0, 0, 0, 0 };
    g_obj_real_zone = { 0, 0, 0, 0 };
    sprite_file_path = "";
    texture_name = "main_hero";
    error_text = "";
    cur_row = 1;
    cur_frame = 0;

    texture_mgr = new TextureMgr();
}

MainHero::~MainHero()
{
    delete texture_mgr;
    debug() << "MainHero end\n";
}

bool MainHero::init(SDL_Renderer *renderer)
{
    if (texture_mgr->load(sprite_file_path, texture_name, renderer))
        return true;
    else
    {
        error_text = SDL_GetError();
        return false;
    }
}

void MainHero::draw(SDL_Renderer *renderer)
{
    //texture_mgr->draw(texture_name, g_obj_zone.x, g_obj_zone.y, g_obj_zone.w, g_obj_zone.h, renderer);
    texture_mgr->drawFrame(texture_name, g_obj_zone.x, g_obj_zone.y, g_obj_zone.w, g_obj_zone.h, cur_row, cur_frame, renderer);
}

void MainHero::setTextureRowAndFrame(int row, int frame)
{
    if (row < 1)
        row = 1;
    cur_row = row;

    if (frame < 0)
        frame = 0;
    cur_frame = frame;
}