# include "CFG.h"

int CCFG::GAME_HEIGHT = 480;
int CCFG::GAME_WIDTH = 800;

int CCFG::keyIDA = 0;
int CCFG::keyIDB = 0;
int CCFG::keyIDX = 0;
int CCFG::keyIDY = 0;

int CCFG::keyIDUp = 0;
int CCFG::keyIDDown = 0;
int CCFG::keyIDLeft = 0;
int CCFG::keyIDRight = 0;

bool CCFG::canMoveBackward = true;
// 一些类的定义
MenuManager* CCFG::oMM = new MenuManager();
CImg* CCFG::tLogo = new CImg();
Text* CCFG::tText = new Text();
Music* CCFG::oMusic = new Music();
Text* CCFG::getText(){
    return tText;
}

MenuManager* CCFG::getMM(){
    return oMM;
}

CImg* CCFG::getLogo(){
    return tLogo;
}

Music* CCFG::getMusic(){
	return oMusic;
}

std::string CCFG::getKeyString(int keyID) {
	if(keyID >= 97 && keyID <= 122) {
		return std::string(1, '0' + (keyID - 32) - 48);
	}

	if(keyID >= 48 && keyID <= 57) {
		return std::string(1, '0' + (keyID - 32) - 48);
	}

	switch(keyID) {
		case SDLK_ESCAPE:
			return "ESCAPE";
		case SDLK_SPACE:
			return "SPACE";
		case SDLK_LSHIFT:
			return "LSHIFT";
		case SDLK_RSHIFT:
			return "RSHIFT";
		case SDLK_UP:
			return "UP";
		case SDLK_DOWN:
			return "DOWN";
		case SDLK_RIGHT:
			return "RIGHT";
		case SDLK_LEFT:
			return "LEFT";
		case SDLK_LCTRL:
			return "LCTRL";
		case SDLK_RCTRL:
			return "RCTRL";
	}

	return "NONE";
}
