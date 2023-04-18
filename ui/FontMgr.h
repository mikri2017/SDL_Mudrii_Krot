#ifndef FONTMGR_H_INCLUDED
#define FONTMGR_H_INCLUDED

#include "../MainConstants.h"
#include <string>
#include <memory>
#include "../Creator.h"
#include <SDL2/SDL_ttf.h>

namespace ui {

enum fontAlign {
    right,
    left,
    centre
};

class FontMgr : public utils::Creator<FontMgr>
{
private:
    TTF_Font *font;
    std::string font_name;
    int font_size;
    SDL_Color font_color;

    int letter_size_px;
    int scn_indent;
    int x_start_left, x_start_right;
public:
    FontMgr();
    ~FontMgr();
    void setLetterSizeInPX(size_t l_size_px);
    void setFontName(std::string f_name);
    void setFontSize(int f_size);
    void setFontColor(const SDL_Color &f_color);
    void setTextXStartFrom(int x_left = 0, int x_right = SCREEN_WIDTH);
    void paintText(SDL_Renderer *renderer, std::string text, int y, int h, fontAlign f_align = fontAlign::right);
    void reloadFont();
};

using FontMgrPtr = std::shared_ptr<FontMgr>;

} // namespace ui

#endif // FONTMGR_H_INCLUDED
