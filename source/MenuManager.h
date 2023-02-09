# pragma once
# ifndef MENUMANAGER_H
# define MENUMANAGER_H
# include "Text.h"
# include "MainMenu.h"
# include "OptionsMenu.h"
# include "AboutMenu.h"
# include "PauseMenu.h"
# include "LoadingMenu.h"

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

    MainMenu* getMainMenu();
    AboutMenu* getAboutMenu();
    PauseMenu* getPauseMenu();
    LoadingMenu* getLoadingMenu();
private:
    MainMenu* oMainMenu;
    OptionsMenu* oOptionsMenu;
    AboutMenu* oAboutMenu;
    PauseMenu* oPauseMenu;
    LoadingMenu* oLoadingMenu;
    gameState currentGameState;
    CImg* activeOption;
};

# endif
