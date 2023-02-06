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
    enum MainMenuState{
        mainSTART,
        mainABOUT,
        mainOPTIONS
    };
public:
    MainMenu();
    ~MainMenu();

    void escape();
    void enter();
    void Draw(SDL_Renderer* rR);
    void Update();
    void updateActiveButton(int iDir);
};

# endif
