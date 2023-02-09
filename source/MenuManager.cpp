# include "MenuManager.h"
# include "Application.h"

MenuManager::MenuManager(){
    this->currentGameState = eMainMenu;
    this->oMainMenu = new MainMenu();
    this->oOptionsMenu = new OptionsMenu();
    this->oAboutMenu = new AboutMenu();
    this->oLoadingMenu = new LoadingMenu();
    this->oPauseMenu = new PauseMenu();
    this->activeOption = NULL;
}

MenuManager::~MenuManager(){
    delete oMainMenu;
    delete oOptionsMenu;
    delete oAboutMenu;
    delete oPauseMenu;
    delete oLoadingMenu;
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
        case eGameLoading:
			SDL_SetRenderDrawColor(rR, 0, 0, 0, 255);
			break;
		case eGame:
			break;
		case eAbout:
			oAboutMenu->setBackgroundColor(rR);
			break;
        default:
            break;
    }
}

void MenuManager::Draw(SDL_Renderer* rR){
    switch(currentGameState){
        case eMainMenu:
            oMainMenu->Draw(rR);
            break;
        case eOptions:
            oOptionsMenu->Draw(rR);
            break;
        case eAbout:
            oAboutMenu->Draw(rR);
            break;
        case ePause:
            oPauseMenu->Draw(rR);
            break;
        case eGameLoading:
            oLoadingMenu->Draw(rR);
            break;
        case eGame:
            //Application::getMap()->Draw(rR);
            break;
        default:
            break;
    }
}

void MenuManager::Update(){
    switch (currentGameState){
        case eMainMenu:
			oMainMenu->Update();
        case eOptions:
            oOptionsMenu->Update();
            break;
        case eAbout:
            oAboutMenu->Update();
            break;
        case ePause:
            oPauseMenu->Update();
            break;
        case eGameLoading:
            oLoadingMenu->Update();
            break;
        case eGame:
            break;
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
        case eOptions:
            oOptionsMenu->updateActiveButton(iDir);
            break;
        case eGameLoading:
            oLoadingMenu->updateActiveButton(iDir);
            break;
        case ePause:
            oPauseMenu->updateActiveButton(iDir);
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
			oAboutMenu->enter();
			break;
		case eOptions:
			oOptionsMenu->enter();
			break;
        case eGameLoading:
            oLoadingMenu->enter();
            break;
		case ePause:
			oPauseMenu->enter();
			break;
        default:
            break;
    }
}

void MenuManager::escape() {
	switch(currentGameState) {
		case eGame:

			break;
		case eAbout:
			oAboutMenu->enter();
			break;
		case eOptions:
			oOptionsMenu->escape();
			break;
		case ePause:
			oPauseMenu->escape();
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

AboutMenu* MenuManager::getAboutMenu(){
    return oAboutMenu;
}

MainMenu* MenuManager::getMainMenu(){
    return oMainMenu;
}

LoadingMenu* MenuManager::getLoadingMenu(){
    return oLoadingMenu;
}

PauseMenu* MenuManager::getPauseMenu(){
    return oPauseMenu;
}

void MenuManager::resetGameState(gameState state){
    switch (state){
    case eMainMenu:
        oMainMenu->setactiveMenuOption(0);
        break;
    case eOptions:
        //选项按钮
        oOptionsMenu->setactiveMenuOption(0);
        break;
    case ePause:
        //暂停按钮选项
        oPauseMenu->setactiveMenuOption(0);
        break;
    default:
        break;
    }
}

void MenuManager::setKey(int keyID){
    switch(currentGameState){
        case eOptions:
            oOptionsMenu->setKey(keyID);
            break;
        default:
            break;
    }
}

