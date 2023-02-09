# ifndef PAUSEMENU_H
# define PAUSEMENU_H
# include "Menu.h"

class PauseMenu:public Menu{
public:
    PauseMenu();
    ~PauseMenu();
    void Draw(SDL_Renderer* rR);
    void Update();

    void enter();
    void escapse();
};

# endif

