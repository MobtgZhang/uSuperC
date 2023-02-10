# include "LoadingMenu.h"
# include "CFG.h"


LoadingMenu::LoadingMenu(){
    this->iTime = SDL_GetTicks();
    this->loadingType = true;
    this->lMO.push_back(new MenuOption("CONTINUE",354,298));
    this->lMO.push_back(new MenuOption("END",354,346));
    this->numOfMenuOptions = 2;
    this->iTimeGameOver = SDL_GetTicks();
}

LoadingMenu::~LoadingMenu(){

}

void LoadingMenu::setLoadingType(bool loadingType){
    this->loadingType = loadingType;
}

void LoadingMenu::updateTime(){
    this->iTime = SDL_GetTicks();
    this->iTimeGameOver = SDL_GetTicks();
}

void LoadingMenu::Update(){
	if(SDL_GetTicks() >= iTime + 2500 + (loadingType ? 0 : 2750)) {
		if(loadingType) {
			CCFG::getMM()->setGameState(CCFG::getMM()->eGame);
            CCFG::getMusic()->PlayMusic(Music::mSTAGE1);
			//CCFG::getMusic()->changeMusic(true, true);
		} else {
			//Application::getMap()->resetGameData();
			//CCFG::getMM()->setGameState(CCFG::getMM()->eMainMenu);
		}
	} else {
		CCFG::getMusic()->StopMusic();
	}
	//Application::getMap()->UpdateBlocks();
}


void LoadingMenu::Draw(SDL_Renderer* rR){
    if(loadingType) {
		//Application::getMap()->DrawGameLayout(rR);
		//HI值
        CCFG::getText()->Draw(rR, "HI SCORE",300, 64);
        CCFG::getText()->Draw(rR, "0020000", 320, 112);

		//1P得分值
        CCFG::getText()->Draw(rR, "1P SCORE", 32, 160);
        CCFG::getText()->Draw(rR, "0000000", 48, 208);
        //生命值
        CCFG::getText()->Draw(rR, "REST 03", 48, 256);
        //2P得分值
        CCFG::getText()->Draw(rR, "2P SCORE", 608, 160);
        CCFG::getText()->Draw(rR, "0000000", 624, 208);
        //生命值
        CCFG::getText()->Draw(rR, "REST 03", 624, 256);

        //场景名字
        CCFG::getText()->Draw(rR, "AREA 1", 300, 320);
        
	} else {
        if(SDL_GetTicks()-this->iTimeGameOver<4000){
            //HI值
            CCFG::getText()->Draw(rR, "HI SCORE",300, 64);
            CCFG::getText()->Draw(rR, "0020000", 320, 112);

            //1P得分值
            CCFG::getText()->Draw(rR, "1P SCORE", 32, 160);
            CCFG::getText()->Draw(rR, "0000000", 48, 208);
            //生命值
            CCFG::getText()->Draw(rR, "REST 03", 48, 256);
            //2P得分值
            CCFG::getText()->Draw(rR, "2P SCORE", 608, 160);
            CCFG::getText()->Draw(rR, "0000000", 624, 208);
            //生命值
            CCFG::getText()->Draw(rR, "REST 03", 624, 256);

            //场景名字
            CCFG::getText()->Draw(rR, "GAME OVER", 300, 320);
        }else{
            //HI值
            CCFG::getText()->Draw(rR, "HI SCORE",300, 64);
            CCFG::getText()->Draw(rR, "0020000", 320, 112);

            //1P得分值
            CCFG::getText()->Draw(rR, "1P SCORE", 32, 160);
            CCFG::getText()->Draw(rR, "0000000", 48, 208);
            //生命值
            CCFG::getText()->Draw(rR, "REST 03", 48, 256);
            //2P得分值
            CCFG::getText()->Draw(rR, "2P SCORE", 608, 160);
            CCFG::getText()->Draw(rR, "0000000", 624, 208);
            //生命值
            CCFG::getText()->Draw(rR, "REST 03", 624, 256);

            // 显示游戏结束和选项
            Menu::Draw(rR);
        }
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
