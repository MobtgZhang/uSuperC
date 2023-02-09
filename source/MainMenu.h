# pragma once
# ifndef MAINMENU_H
# define MAINMENU_H

# include"CImg.h"
# include"Menu.h"

class MainMenu:public Menu{
private:
    bool selectLevel;
    int activeLevelID;
    SDL_Rect rSelectLevel;

    unsigned int twinkleTime;
    unsigned int iTime;
    //设置菜单按钮是否闪烁
    bool twinkle;
public:
    enum MainMenuState{
        mainSTART,
        mainOPTIONS,
        mainABOUT,
    };
    MainMenu();
    ~MainMenu();

    void escape();
    void enter();
    void Draw(SDL_Renderer* rR);
    void Update();
    void updateActiveButton(int iDir);
    //设置菜单选项图标是否闪烁
    void setTwinkle(bool twinkle);
    void updateTime();
};

# endif
