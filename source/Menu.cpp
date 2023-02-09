# include "Menu.h"
# include "CFG.h"

# include<iostream>

Menu::Menu(){
    this->activeMenuOption = 0;
    this->twinkle = false;
    this->active_draw = false;
}

Menu::~Menu(){

}


void Menu::Draw(SDL_Renderer* rR){
    for(unsigned int k=0;k<lMO.size();k++){
        CCFG::getText()->Draw(rR,lMO[k]->getText(),lMO[k]->getXPos(),lMO[k]->getYPos());
    }

    if(!twinkle){
        CCFG::getMM()->getActiveOption()->Draw(rR,lMO[activeMenuOption]->getXPos()-48,lMO[activeMenuOption]->getYPos()-4);
    }else{
        if(SDL_GetTicks() - this->twinkleTime>250){
            active_draw = !active_draw;
            this->twinkleTime = SDL_GetTicks();
        }
        if(active_draw){
            CCFG::getMM()->getActiveOption()->Draw(rR,lMO[activeMenuOption]->getXPos()-48,lMO[activeMenuOption]->getYPos()-4);
        }
    }
}

void Menu::setactiveMenuOption(int num_ID){
    this->activeMenuOption = num_ID;
}


void Menu::setTwinkle(bool twinkle){
    this->twinkle = twinkle;
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
