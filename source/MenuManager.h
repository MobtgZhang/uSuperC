# pragma once
# ifndef MENUMANAGER_H
# define MENUMANAGER_H
# include "MainMenu.h"
# include "OptionsMenu.h"
# include "Text.h"

class MenuManager{

public:

    enum gameState{
        eMainMenu,
        eGameLoading,
        eGame,
        eAbout,
        eOptions,
        ePause
    };
    MenuManager();
    ~MenuManager();

    gameState getGameState();
    void setGameState(gameState state);
    void setBackgroundColor(SDL_Renderer* rR);
    void Draw(SDL_Renderer* rR);
    void Update();
    
    CImg* getActiveOption();
    void setActiveOption(SDL_Renderer* rR);

    void keyPressed(int iDir);
    void enter();
    void escape();
    OptionsMenu* getOptionsMenu();
private:
    MainMenu* oMainMenu;
    OptionsMenu* oOptionsMenu;
    gameState currentGameState;
    CImg* activeOption;
};

# endif
