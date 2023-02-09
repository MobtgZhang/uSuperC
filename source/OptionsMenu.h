# pragma once
# ifndef OPTIONSMENU_H
# define OPTIONSMENU_H

# include "Menu.h"

class OptionsMenu:public Menu{
private:
    SDL_Rect rRect;
    SDL_Rect rSetKeyRect;
    SDL_Rect rVolumeBG;
    SDL_Rect rVolume;
    
    bool inSetKey,resetSetKey;

    bool escapeToMainMenu;
public:
    enum OptionMenuState{
        optionVOLUME,
        optionLEFT,
        optionDOWN,
        optionRIGHT,
        optionUP,
        optionA,
        optionB,
        optionX,
        optionY,
        optionMOVEBACKWARD,
        optionMAINMENU
    };
    OptionsMenu();
    ~OptionsMenu();

    void escape();
    void enter();
    void setKey(int keyID);
    void setEscapeToMainMenu(bool escapeToMainMenu);
    void updateVolumeRect();

    void updateActiveButton(int iDir);
    void Draw(SDL_Renderer* rR);
    void Update();

};
# endif
