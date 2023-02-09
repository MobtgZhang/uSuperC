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
    // 设置是否遮罩
    bool active_draw;
    // 闪烁时间
    unsigned int twinkleTime;
    //设置菜单按钮是否闪烁
    bool twinkle;

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
    void setactiveMenuOption(int num_ID);
    // 菜单按钮是否闪烁
    
    void setTwinkle(bool twinkle);
};

# endif
