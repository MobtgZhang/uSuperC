# include "AboutMenu.h"
# include "CFG.h"

AboutMenu::AboutMenu(){
    lMO.push_back(new MenuOption("MAIN MENU",150,340));

    this->numOfMenuOptions = lMO.size();
    
    this->cR = 0;
    this->cG = 0;
    this->cB = 0;
    this->nR = 0;
    this->nG = 0;
    this->nB = 0;

    this->colorStepID = 1;
    this->iColorID = 0;

    srand((unsigned)time(NULL));
}

AboutMenu::~AboutMenu(){

}

void AboutMenu::Draw(SDL_Renderer* rR){
    CCFG::getText()->DrawWS(rR, "CONTRA V 1.0 - C++ AND SDL2", 150, 128, 0, 0, 0);
	CCFG::getText()->DrawWS(rR, "AUTHOR: MOBTGZHANG", 150, 160, 0, 0, 0);

	CCFG::getText()->DrawWS(rR, "CREATE IN YEAR OF 2023", 150, 192, 0, 0, 0);
	CCFG::getText()->DrawWS(rR, "MOBTGZHANG.GITHUB.IO", 150, 224, 0, 0, 0);

	for(unsigned int i = 0; i < lMO.size(); i++) {
		CCFG::getText()->DrawWS(rR, lMO[i]->getText(), lMO[i]->getXPos(), lMO[i]->getYPos(), 0, 0, 0);
	}

	CCFG::getMM()->getActiveOption()->Draw(rR, lMO[activeMenuOption]->getXPos() - 48, lMO[activeMenuOption]->getYPos()-4);
}


void AboutMenu::Update(){
    if(SDL_GetTicks() >= iTime + 35){
        this->cR = getColorStep(cR,nR);
        this->cG = getColorStep(cG,nG);
        this->cB = getColorStep(cB,nB);
        if (colorStepID >= 15 || (cR == nR && cG == nG && cB == nB)) {
			nextColor();
			colorStepID = 1;
		} else {
			++colorStepID;
		}
        iTime = SDL_GetTicks();
    }
}

void AboutMenu::enter(){
    CCFG::getMM()->resetGameState(CCFG::getMM()->eMainMenu);
    CCFG::getMM()->setGameState(CCFG::getMM()->eMainMenu);
    //reset();
    CCFG::getMusic()->StopMusic();
}

void AboutMenu::setBackgroundColor(SDL_Renderer* rR) {
	SDL_SetRenderDrawColor(rR, cR, cG, cB, 255);
}


void AboutMenu::updateTime(){
    this->iTime = SDL_GetTicks();
}

int AboutMenu::getColorStep(int iOld, int iNew) {
	return iOld + (iOld > iNew ? (iNew - iOld) * colorStepID / 30 : (iNew - iOld) * colorStepID / 30);
}


void AboutMenu::nextColor() {
	int iN = iColorID;

	while(iN == iColorID) {
		iColorID = rand() % 16;
	}

	++iColorID;

	switch (iColorID) {
		case 0:
			nR = 73;
			nG = 133;
			nB = 203;
			break;
		case 1:
			nR = 197;
			nG = 197;
			nB = 223;
			break;
		case 2:
			nR = 27;
			nG = 60;
			nB = 173;
			break;
		case 3:
			nR = 6;
			nG = 21;
			nB = 86;
			break;
		case 4:
			nR = 183;
			nG = 85;
			nB = 76;
			break;
		case 5:
			nR = 110;
			nG = 58;
			nB = 70;
			break;
		case 6:
			nR = 55;
			nG = 19;
			nB = 63;
			break;
		case 7:
			nR = 115;
			nG = 53;
			nB = 126;
			break;
		case 8:
			nR = 227;
			nG = 200;
			nB = 0;
			break;
		case 9:
			nR = 255;
			nG = 180;
			nB = 2;
			break;
		case 10:
			nR = 231;
			nG = 51;
			nB = 24;
			break;
		case 11:
			nR = 255;
			nG = 180;
			nB = 2;
			break;
		case 12:
			nR = 4;
			nG = 2;
			nB = 15;
			break;
		case 13:
			nR = 135;
			nG = 178;
			nB = 168;
			break;
		case 14:
			nR = 64;
			nG = 43;
			nB = 24;
			break;
		case 15:
			nR = rand() % 255;
			nG = rand() % 255;
			nB = rand() % 255;
			break;
	}
}
