# pragma once
# ifndef MENU_H
# define MENU_H

# include <vector>
# include <SDL2/SDL.h>

# include"MenuOption.h"

class Menu{ 
protected:
    std::vector<MenuOption*> lMO;
    int activeMenuOption;
    int numOfMenuOptions;
public:
    enum MenuItemAction{
        iUP_ITEM,
        iDOWN_ITEM,
        iLEFT_ITEM,
        iRIGHT_ITEM
    };
    Menu();
    ~Menu();

    virtual void Update();
    virtual void Draw(SDL_Renderer* rR);
	virtual void updateActiveButton(int iDir);
};

# endif
