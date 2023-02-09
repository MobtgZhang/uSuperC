# include "MainMenu.h"
# include "MenuOption.h"
# include "CFG.h"
# include "Application.h"

# include<iostream>

MainMenu::MainMenu(){
    this->lMO.push_back(new MenuOption("START",256,256));
    this->lMO.push_back(new MenuOption("OPTIONS",256,288));
    this->lMO.push_back(new MenuOption("ABOUT",256,320));
    
    rSelectLevel.x = 122;
	rSelectLevel.y = 280;
	rSelectLevel.w = 306;
	rSelectLevel.h = 72;
    
    this->numOfMenuOptions = lMO.size();
    this->activeMenuOption = mainSTART;
    this->selectLevel = false;
    this->activeLevelID = 0;
    this->iTime = SDL_GetTicks();
    this->twinkleTime = SDL_GetTicks();
    //设置菜单是否闪烁
    this->twinkle = false;
}

MainMenu::~MainMenu(){

}

void MainMenu::setTwinkle(bool twinkle){
    Menu::setTwinkle(twinkle);
    this->twinkle = twinkle;    
}

void MainMenu::Draw(SDL_Renderer* rR){
    CCFG::getLogo()->Draw(rR,160,0);
    Menu::Draw(rR);
    
	CCFG::getText()->Draw(rR, "AUTHOR:MOBTGZHANG", 5, CCFG::GAME_HEIGHT - 16, 8, 255, 255, 255);
    if(selectLevel){
        SDL_SetRenderDrawBlendMode(rR,SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(rR,4,4,4,235);
        SDL_RenderFillRect(rR, &rSelectLevel);
		SDL_SetRenderDrawColor(rR, 255, 255, 255, 255);
        rSelectLevel.x += 1;
		rSelectLevel.y += 1;
		rSelectLevel.h -= 2;
		rSelectLevel.w -= 2;
		SDL_RenderDrawRect(rR, &rSelectLevel);
		rSelectLevel.x -= 1;
		rSelectLevel.y -= 1;
		rSelectLevel.h += 2;
		rSelectLevel.w += 2;

        CCFG::getText()->Draw(rR, "SELECT LEVEL", rSelectLevel.x + rSelectLevel.w/2 - CCFG::getText()->getTextWidth("SELECT LEVEL")/2, rSelectLevel.y + 16, 16, 255, 255, 255);
        for(int i = 0, extraX = 0; i < 8; i++) {
			if(i == activeLevelID) {
				CCFG::getText()->Draw(rR, std::to_string(i + 1) , rSelectLevel.x + 16*(i + 1) + 16*i + extraX, rSelectLevel.y + 16 + 24, 16, 255, 255, 255);
			} else {
				CCFG::getText()->Draw(rR, std::to_string(i + 1), rSelectLevel.x + 16*(i + 1) + 16*i + extraX, rSelectLevel.y + 16 + 24, 16, 90, 90, 90);
			}
		}

		SDL_SetRenderDrawBlendMode(rR, SDL_BLENDMODE_NONE);
		//Application::getMap()->setBackgroundColor(rR);
    }
}

void MainMenu::escape(){
    selectLevel = false;
}

void MainMenu::enter(){
    if(twinkle){
       return; 
    }
    switch(activeMenuOption){
        case MainMenu::mainSTART:
            if(!selectLevel){
                selectLevel = true;
            }else{
                selectLevel = false;
                CCFG::getMM()->getMainMenu()->setTwinkle(true);
                CCFG::getMM()->getMainMenu()->updateTime();
                //这里进入到某一个关卡当中
                // setworld etc.
                CCFG::getMM()->getLoadingMenu()->setLoadingType(true);
            }
            break;
        case MainMenu::mainOPTIONS:
            //选项菜单
            CCFG::getMM()->getOptionsMenu()->setEscapeToMainMenu(true);
            CCFG::getMM()->resetGameState(CCFG::getMM()->eOptions);
            CCFG::getMM()->getOptionsMenu()->updateVolumeRect();
            CCFG::getMM()->setGameState(CCFG::getMM()->eOptions);
            break;
        case MainMenu::mainABOUT:
            //关于菜单
            CCFG::getMM()->getAboutMenu()->updateTime();
            CCFG::getMM()->setGameState(CCFG::getMM()->eAbout);
            CCFG::getMusic()->PlayMusic(CCFG::getMusic()->mSTAGE1);
            break;
        default:
            break;
    }
}

void MainMenu::updateTime(){
    this->iTime = SDL_GetTicks();
}

void MainMenu::updateActiveButton(int iDir){
    if(twinkle){
        return; 
    }
    switch(iDir){
        case iUP_ITEM:case iDOWN_ITEM:
            if(!selectLevel){
                Menu::updateActiveButton(iDir);
            }
            break;
        case iLEFT_ITEM:
            if(selectLevel){
                if(activeLevelID >0){
                    --activeLevelID;
                }else{
                    activeLevelID = 7;
                }
            }
            break;
        case iRIGHT_ITEM:
            if(selectLevel){
                if(activeLevelID < 7) {
					++activeLevelID;
				} else {
					activeLevelID = 0;
				}
            }
            break;
    }
}

void MainMenu::Update(){
    if(twinkle){
        if(SDL_GetTicks() - this->iTime>=2000 && CCFG::getMM()->getGameState()==CCFG::getMM()->eMainMenu){
            CCFG::getMM()->setGameState(CCFG::getMM()->eGameLoading);
            CCFG::getMM()->getMainMenu()->setTwinkle(false);
            CCFG::getMM()->getLoadingMenu()->updateTime();
            //CCFG::getMusic()->StopMusic();
        }
    }
    Menu::Update();
}

