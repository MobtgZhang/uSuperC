# ifndef LOADINGMENU_H
# define LOADINGMENU_H
# include "Menu.h"

class LoadingMenu:public Menu{
public:
    LoadingMenu();
    ~LoadingMenu();
    void updateActiveButton(int iDir);  
};

# endif
