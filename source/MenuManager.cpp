# include "MenuManager.h"
MenuManager::MenuManager(){
    this->currentGameState = eMainMenu;
    this->oMainMenu = new MainMenu();
    this->activeOption = NULL;
}

MenuManager::~MenuManager(){
    delete oMainMenu;
}

MenuManager::gameState MenuManager::getGameState(){
    return currentGameState;
}
void MenuManager::setGameState(gameState state){
    this->currentGameState = state;
}


void MenuManager::setBackgroundColor(SDL_Renderer* rR){
    switch (currentGameState){
    case eMainMenu:
        SDL_SetRenderDrawColor(rR,0,0,0,255);
        break;
    default:
        break;
    }
}

void MenuManager::Draw(SDL_Renderer* rR){
    switch(currentGameState){
        case eMainMenu:
            oMainMenu->Draw(rR);
    }
}

void MenuManager::Update(){
    switch (currentGameState){
        case eMainMenu:
			oMainMenu->Update();
        default:
            break;
    }
}

CImg* MenuManager::getActiveOption(){
    return activeOption;
}

void MenuManager::setActiveOption(SDL_Renderer* rR) {
	activeOption = new CImg("active_option", rR);
}

void MenuManager::keyPressed(int iDir){
    switch(currentGameState){
        case eMainMenu:
            oMainMenu->updateActiveButton(iDir);
            break;
        default:
            break;
    }
}

void MenuManager::enter(){
    switch(currentGameState){
        case eMainMenu:
			oMainMenu->enter();
			break;
		case eGame:
			//Application::getMap()->setDrawLines(!Application::getMap()->getDrawLines());
			break;
		case eAbout:
			//oAboutMenu->enter();
			break;
		case eOptions:
			//oOptionsMenu->enter();
			break;
		case ePause:
			//oPauseMenu->enter();
			break;
    }
}

void MenuManager::escape() {
	switch(currentGameState) {
		case eGame:
			break;
		case eAbout:
			//oAboutMenu->enter();
			break;
		case eOptions:
			//oOptionsMenu->escape();
			break;
		case ePause:
			//oPauseMenu->escape();
			break;
		case eMainMenu:
			oMainMenu->escape();
			break;
        default:
            break;
	}
}

OptionsMenu* MenuManager::getOptionsMenu(){
    return oOptionsMenu;
}

