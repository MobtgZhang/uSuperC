# ifndef APPLICATION_H
# define APPLICATION_H
# include <SDL2/SDL.h>
# include "Map.h"

class Application{
private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Event* mainEvent;

    // ----- FPS -----
    long frameTime;
    static const int MIN_FRAME_TIME = 16;
    unsigned long lFPSTime;
    int iNumOfFPS,iFPS;

    // ----- INPUT KEYS -----
    static bool keyLeftPressed,keyRightPressed;
    static bool keyUp,keyDown,keyLeft,keyRight;
    static bool keyA,keyB,keyX,keyY;
    static bool keyMenuPressed;

    static Map* oMap;
public:
    Application();
    ~Application();
    void mainloop();
    void Draw();
    void Update();
    void Input();
    //加载主菜单信息
    void InputMenu();
    // 加载玩家信息
    void InputLayer();
    // 设置游戏退出
    static bool quitGame;
    // 加载地图信息
    static Map* getMap();
};

# endif
