#ifndef MAINHERO_H_INCLUDED
#define MAINHERO_H_INCLUDED

#include "GameObject.h"
#include <SDL2/SDL.h>

class TextureMgr;

class MainHero : public GameObject
{
private:
    SDL_Texture *hero_texture;
    TextureMgr *texture_mgr;
    std::string texture_name;
    int cur_row, cur_frame;
public:
    MainHero();
    ~MainHero();
    bool init(SDL_Renderer *renderer);
    void draw(SDL_Renderer *renderer);
    void setTextureRowAndFrame(int row, int frame);
};

#endif // MAINHERO_H_INCLUDED