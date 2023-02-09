# ifndef PAUSEMENU_H
# define PAUSEMENU_H

# include "Menu.h"

class PauseMenu: public Menu{
private:
    SDL_Rect rPause;
public:
    PauseMenu();
    ~PauseMenu();
    
    enum PauseMenuItem{
        pRESUME,
        pOPTIONS,
        pQUITTOMENU,
        pQUITTODESKTOP
    };

    void Update();
    void Draw(SDL_Renderer* rR);

    void enter();
    void escape();

    void updateActiveButton(int iDir);
};

# endif
