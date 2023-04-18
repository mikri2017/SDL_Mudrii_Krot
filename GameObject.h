#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include <SDL2/SDL.h>
#include <string>

class GameObject
{
protected:
    SDL_Rect g_obj_zone;
    SDL_Rect g_obj_real_zone;
    std::string sprite_file_path;
    std::string error_text;
public:
    virtual ~GameObject() {};
    virtual std::string getErrorText();
    virtual bool init(SDL_Renderer *renderer) = 0;
    virtual void draw(SDL_Renderer *renderer) = 0;
    virtual SDL_Rect getGameObjectZone();
    virtual SDL_Rect getGameObjectRealZone();
    virtual int getPositionBeginX();
    virtual int getPositionBeginY();
    virtual int getRealPositionBeginX();
    virtual int getRealPositionBeginY();
    virtual void setPosition(int x, int y);
    virtual void setRealPosition(int x, int y);
    virtual int getWidth();
    virtual int getHeight();
    virtual void setWidthHeight(int w, int h);
    virtual void setSpriteFilePath(std::string file_path);
    virtual int getCurTextureRow() = 0;
    virtual int getCurTextureFrame() = 0;
    virtual void setTextureRowAndFrame(int row, int frame) = 0;
};

#endif // GAMEOBJECT_H_INCLUDED