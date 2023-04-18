#include "MainConstants.h"
#include "SceneGame.h"
#include "LangMgr.h"
#include "Debug.h"
#include <iostream>


SceneGame::SceneGame()
{
    // Инициализируем языковой модуль
    lang_mgr = LangMgr::Init();

    // Выставляем количество жизней
    lives = 3;
    lives_caption = lang_mgr->getPhrase("scene_lives") + ": " + std::to_string(lives);

    // Задаем параметры главного персонажа
    hero = new MainHeroMgr();
    hero->setRealPosition(10, 350);
    hero->setWidthHeight(56, 71);
    hero->setSpriteFilePath("assets/sprites/main_hero/Grue.png");
    hero->setMoveStep(15);

    // Задаем параметры текста
    font_color = {0, 0, 255};

    font_game_info = new ui::FontMgr();
    font_game_info->setFontName("assets/fonts/XoloniumBold.ttf");
    font_game_info->setFontSize(26);
    font_game_info->setFontColor(font_color);
    font_game_info->setLetterSizeInPX(20);

    // Задаем параметры камеры
    cam_main = new Camera();
    cam_main->setPosition(0, 0);
    cam_main->setWidthHeight(SCREEN_WIDTH, SCREEN_HEIGHT);
    cam_main->setGameObjectForWatch(hero);
    cam_main->setGameObjectRelativePos(SCREEN_WIDTH / 2 - hero->getWidth(), 350);
    cam_main->setGameObjectWatchingMode(true);
    cam_main->updatePosition();
    SDL_Rect hero_pos = cam_main->getGameObjectAreaInCam(hero);
    hero->setPosition(hero_pos.x, hero_pos.y);
}

SceneGame::~SceneGame()
{
    delete font_game_info;
    delete cam_main;
    delete hero;
    debug() << "SceneGame end" << std::endl;
}

void SceneGame::render(SDL_Renderer *renderer)
{
    if (!b_paused)
    {
        if (b_first_render)
        {
            setFirstRenderState(false);
            if (!hero->init(renderer))
                std::cout << "Error: " << hero->getErrorText() << std::endl;
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        hero->draw(renderer);

        font_game_info->paintText(renderer, lives_caption, SCREEN_HEIGHT - 30, 30, ui::fontAlign::right);

        SDL_RenderPresent(renderer);
    }
}

void SceneGame::render_clean(SDL_Renderer *renderer)
{
    // Стираем текущие объекты сцены
}

gameReaction SceneGame::process_mouse_motion(Sint32 x, Sint32 y)
{
    if (!b_paused)
    {
    }

    return gameReaction::gr_ignore;
}

gameReaction SceneGame::process_mouse_button_event(SDL_MouseButtonEvent m_btn_event)
{
    return gameReaction::gr_ignore;
}

gameReaction SceneGame::process_keyboard_keydown(SDL_Keycode keycode)
{
    if (!b_paused)
    {
        hero->process_keyboard_keydown(keycode);
        cam_main->updatePosition();

        //SDL_Rect hero_pos = hero->getGameObjectRealZone();
        SDL_Rect hero_pos = cam_main->getGameObjectAreaInCam(hero);
        hero->setPosition(hero_pos.x, hero_pos.y);
        debug() << "hero_x: " << hero_pos.x << " hero_y: " << hero_pos.y << "\n";
        debug() << "cam_x: " << cam_main->getPositionBeginX() << " cam_y: " << cam_main->getPositionBeginY() << "\n\n";
    }

    return gameReaction::gr_ignore;
}
