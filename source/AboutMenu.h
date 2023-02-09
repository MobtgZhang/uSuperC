# pragma once
# ifndef ABOUTMENU_H
# define ABOUTMENU_H

# include "Menu.h"
# include "AboutMenu.h"


class AboutMenu:public Menu{
private:
    unsigned int iTime;
    int colorStepID,iColorID;
    int cR, cG, cB, nR, nG, nB;
public:
    AboutMenu();
    ~AboutMenu();
    void Draw(SDL_Renderer* rR);
    void Update();
    void enter();
    void updateTime();

    int getColorStep(int iOld, int iNew);
    void nextColor();
    void setBackgroundColor(SDL_Renderer* rR);
};

# endif
