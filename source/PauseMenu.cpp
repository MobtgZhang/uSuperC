# include "PauseMenu.h"
# include "CFG.h"
# include "Application.h"

PauseMenu::PauseMenu(){
    rPause.x = 220;
	rPause.y = 140;
	rPause.w = 360;
	rPause.h = 142;

	this->lMO.push_back(new MenuOption("RESUME", 0, 156));
	this->lMO.push_back(new MenuOption("OPTIONS", 0, 180));

	this->lMO.push_back(new MenuOption("QUIT TO MENU", 0, 228));
	this->lMO.push_back(new MenuOption("QUIT TO DESKTOP", 0, 252));

	this->numOfMenuOptions = lMO.size();
}
PauseMenu::~PauseMenu(){
    
}

void PauseMenu::Update(){
    
}
void PauseMenu::Draw(SDL_Renderer* rR){
    SDL_SetRenderDrawBlendMode(rR, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(rR, 4, 4, 4, 235);
	SDL_RenderFillRect(rR, &rPause);
	SDL_SetRenderDrawColor(rR, 255, 255, 255, 255);
	rPause.x += 1;
	rPause.y += 1;
	rPause.h -= 2;
	rPause.w -= 2;
	SDL_RenderDrawRect(rR, &rPause);
	rPause.x -= 1;
	rPause.y -= 1;
	rPause.h += 2;
	rPause.w += 2;

	for(unsigned int i = 0; i < lMO.size(); i++) {
		if(i == activeMenuOption) {
			CCFG::getText()->DrawCenterX(rR, lMO[i]->getText(), lMO[i]->getYPos(), 16, 255, 255, 255);
		} else {
			CCFG::getText()->DrawCenterX(rR, lMO[i]->getText(), lMO[i]->getYPos(), 16, 90, 90, 90);
		}
	}

	SDL_SetRenderDrawBlendMode(rR, SDL_BLENDMODE_NONE);
	//Application::getMap()->setBackgroundColor(rR);
}

void PauseMenu::enter(){
    switch(activeMenuOption){
        case 0:
            CCFG::getMM()->setGameState(CCFG::getMM()->eGame);
            CCFG::getMusic()->PauseMusic();
            break;
        case 1:
            CCFG::getMM()->getOptionsMenu()->setEscapeToMainMenu(false);
            CCFG::getMM()->resetGameState(CCFG::getMM()->eOptions);
            CCFG::getMM()->getOptionsMenu()->updateVolumeRect();
            CCFG::getMM()->setGameState(CCFG::getMM()->eOptions);
            break;
        case 2:
            //Application::getMap()->resetGameData();
			CCFG::getMM()->setGameState(CCFG::getMM()->eMainMenu);
            CCFG::getMM()->getMainMenu()->setTwinkle(false);
            CCFG::getMusic()->StopMusic();
			break;
        case 3:
            Application::quitGame = true;
            break;
        default:
            break;
    }
}

void PauseMenu::escape(){
    CCFG::getMM()->setGameState(CCFG::getMM()->eGame);
	CCFG::getMusic()->PauseMusic();
}

void PauseMenu::updateActiveButton(int iDir){
    Menu::updateActiveButton(iDir);
}

