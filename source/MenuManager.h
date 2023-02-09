# pragma once
# ifndef MENUMANAGER_H
# define MENUMANAGER_H
# include "MainMenu.h"
# include "OptionsMenu.h"
# include "AboutMenu.h"
# include "LoadingMenu.h"
# include "PauseMenu.h"
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
    void resetGameState(gameState state);
    void setBackgroundColor(SDL_Renderer* rR);
    void Draw(SDL_Renderer* rR);
    void Update();
    
    CImg* getActiveOption();
    void setActiveOption(SDL_Renderer* rR);

    void keyPressed(int iDir);
    void enter();
    void escape();
    void setKey(int keyID);
    OptionsMenu* getOptionsMenu();
    AboutMenu* getAboutMenu();
    MainMenu* getMainMenu();
    LoadingMenu* getLoadingMenu();
    PauseMenu* getPauseMenu();
private:
    MainMenu* oMainMenu;
    OptionsMenu* oOptionsMenu;
    AboutMenu* oAboutMenu;
    LoadingMenu* oLoadingMenu;
    PauseMenu* oPauseMenu;
    gameState currentGameState;
    CImg* activeOption;
};

# endif

