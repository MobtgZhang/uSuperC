# include "Menu.h"
# include "CFG.h"

Menu::Menu(){
    this->activeMenuOption = 0;
}

Menu::~Menu(){

}

void Menu::Draw(SDL_Renderer* rR){
    for(unsigned int k=0;k<lMO.size();k++){
        CCFG::getText()->Draw(rR,lMO[k]->getText(),lMO[k]->getXPos(),lMO[k]->getYPos());
    }
    CCFG::getMM()->getActiveOption()->Draw(rR,lMO[activeMenuOption]->getXPos()-48,lMO[activeMenuOption]->getYPos()-8);
}

void Menu::Update(){

}

void Menu::updateActiveButton(int iDir){
    switch(iDir){
        case iUP_ITEM:
            if(activeMenuOption - 1<0){
                activeMenuOption = numOfMenuOptions - 1;
            }else{
                --activeMenuOption;
            }
            break;
        case iDOWN_ITEM:
            if(activeMenuOption + 1>=numOfMenuOptions){
                activeMenuOption = 0;
            }else{
                ++activeMenuOption;
            }
            break;
        default:
            break;
    }
}