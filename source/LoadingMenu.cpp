# include "LoadingMenu.h"
# include "CFG.h"


LoadingMenu::LoadingMenu(){
    this->iTime;
    this->loadingType = true;
    this->lMO.push_back(new MenuOption("CONTINUE",354,298));
    this->lMO.push_back(new MenuOption("END",354,346));
    this->numOfMenuOptions = 2;

    this->twinkleTime = SDL_GetTicks();
    this->active_draw = false;
}

LoadingMenu::~LoadingMenu(){

}

void LoadingMenu::setLoadingType(bool loadingType){
    this->loadingType = loadingType;
}

void LoadingMenu::updateTime(){
    this->iTime = SDL_GetTicks();
}

void LoadingMenu::Update(){
	if(SDL_GetTicks() >= iTime + 2500 + (loadingType ? 0 : 2750)) {
		if(loadingType) {
			CCFG::getMM()->setGameState(CCFG::getMM()->eGame);
            CCFG::getMusic()->PlayMusic(Music::mSTAGE1);
			//CCFG::getMusic()->changeMusic(true, true);
		} else {
			//Application::getMap()->resetGameData();
			CCFG::getMM()->setGameState(CCFG::getMM()->eMainMenu);
		}
	} else {
		CCFG::getMusic()->StopMusic();
	}
	//Application::getMap()->UpdateBlocks();
}


void LoadingMenu::Draw(SDL_Renderer* rR){
    if(SDL_GetTicks()-this->twinkleTime> 250){
        active_draw = !active_draw;
        this->twinkleTime = SDL_GetTicks();
    }
    if(loadingType) {
		//Application::getMap()->DrawGameLayout(rR);
		//1P得分值
        CCFG::getText()->Draw(rR, "1P", 82, 82);
        
        if(active_draw){
            CCFG::getText()->Draw(rR, "0", 286, 82);
        }
		//生命值
        CCFG::getText()->Draw(rR, "REST", 82, 115);
        CCFG::getText()->Draw(rR, "3", 216, 115);
        //HI值
        CCFG::getText()->Draw(rR, "HI", 256, 115);
        if(active_draw){
            CCFG::getText()->Draw(rR, "20000", 364, 115);
        }
        //场景名字
        CCFG::getText()->Draw(rR, "STAGE 1", 306, 250);
        CCFG::getText()->Draw(rR, "JUNGLE", 306, 282);
        
	} else {
		//这里显示的是哪一个玩家，因为只有一个玩家显示1P
        CCFG::getText()->Draw(rR, "1P", 82, 82);
        //得分值
        if(active_draw){
            CCFG::getText()->Draw(rR, "0", 286, 82);
        }
        //HI值
        CCFG::getText()->Draw(rR, "HI", 256, 115);
        if(active_draw){
            CCFG::getText()->Draw(rR, "20000", 364, 115);
        }
        // 显示游戏结束和选项
        CCFG::getText()->Draw(rR, "GAMEOVER", 306, 250);
        Menu::Draw(rR);

	}
}

void LoadingMenu::updateActiveButton(int iDir){
    switch(iDir){
        case iUP_ITEM:case iDOWN_ITEM:
            if(!loadingType){
                Menu::updateActiveButton(iDir);
            }
            break;
        default:
            break;
        }
}

void LoadingMenu::enter(){
    if(!loadingType){
        switch(activeMenuOption){
            case 0:
                //继续当前游戏关卡
                break;
            case 1:
                CCFG::getMM()->setGameState(CCFG::getMM()->eMainMenu);
                break;
            default:
                break;
        }
    }
}
