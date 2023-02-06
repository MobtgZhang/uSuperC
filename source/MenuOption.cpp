# include "MenuOption.h"

MenuOption::MenuOption(std::string sText,int XPos,int YPos){
    this->sText = sText;
    this->iXPos = XPos;
    this->iYPos = YPos;
}

MenuOption::~MenuOption(){

}

std::string MenuOption::getText(){
    return sText;
}

void MenuOption::setText(std::string sText){
    this->sText = sText;
}

int MenuOption::getXPos(){
    return this->iXPos;
}

int MenuOption::getYPos(){
    return this->iYPos;
}
