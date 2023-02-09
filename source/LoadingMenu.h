# pragma once 

# ifndef LOADINGMENU_H
# define LOADINGMENU_H
# include<SDL2/SDL.h>
# include "Menu.h"
class LoadingMenu: public Menu{
private:
    unsigned int iTime;
    bool loadingType; // -- true = LOADING, false = GAME OVER


    // 设置是否遮罩
    bool active_draw;
    // 闪烁时间
    unsigned int twinkleTime;

public:
    LoadingMenu();
    ~LoadingMenu();

    void Draw(SDL_Renderer* rR);
    void Update();

    void updateTime();
    void setLoadingType(bool loadingType);
    void updateActiveButton(int iDir);
    void enter();
};

# endif
