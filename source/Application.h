# ifndef APPLICATION_H
# define APPLICATION_H
# include <SDL2/SDL.h>

class Application{
private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Event* mainEvent;

    bool quitGame;
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
public:
    Application();
    ~Application();
    void mainloop();
    void Draw();
    void Update();
    void Input();
    void InputMenu();
};

# endif
