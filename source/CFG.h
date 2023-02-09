# ifndef CFG_H
# define CFG_H
# include "MenuManager.h"
# include "Music.h"

class CCFG{
private:
    static MenuManager* oMM;
    static CImg* tLogo;
    static Text* tText;
    static Music* oMusic;
public:
    CCFG();
    ~CCFG();
    //获取主菜单
    static MenuManager* getMM();
    // 获取主菜单图片
    static CImg* getLogo();
    // 获取主菜单文字
    static Text* getText();
    static Music* getMusic();
    static int GAME_HEIGHT,GAME_WIDTH;
    // 控制方向键
    static int keyIDUp,keyIDDown,keyIDLeft,keyIDRight;
    // 控制动作键
    static int keyIDA,keyIDB,keyIDX,keyIDY;
    static bool canMoveBackward;
    // 获取keyID 对应的字符串
    static std::string getKeyString(int keyID);
};

# endif
