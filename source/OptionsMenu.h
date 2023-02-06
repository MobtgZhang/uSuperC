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
    OptionsMenu();
    ~OptionsMenu();
    void setEscapeToMainMenu(bool escapeToMainMenu);
    void updateVolumeRect();
};
# endif
