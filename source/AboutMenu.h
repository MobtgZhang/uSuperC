# ifndef ABOUTMENU_H
# define ABOUTMENU_H
# include "Menu.h"

class AboutMenu:public Menu{
public:
    AboutMenu();
    ~AboutMenu();
    void Draw(SDL_Renderer* rR);
    void Update();

    void enter();
    void escape();
};

# endif
