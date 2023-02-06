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

Text* CCFG::getText(){
    return tText;
}

MenuManager* CCFG::getMM(){
    return oMM;
}

CImg* CCFG::getLogo(){
    return tLogo;
}
