# include "Application.h"
# include "CFG.h"
# include <iostream>

// some initialize parameters
bool Application::keyLeftPressed = false;
bool Application::keyRightPressed = false;
// 游戏控制键
bool Application::keyUp = false;
bool Application::keyDown = false;
bool Application::keyLeft = false;
bool Application::keyRight = false;
bool Application::keyA = false;
bool Application::keyB = false;
bool Application::keyX = false;
bool Application::keyY = false;
//其他按键
bool Application::keyMenuPressed = false;

Application::Application(){
    this->quitGame = false;
    this->iFPS = 0;
    this->iNumOfFPS = 0;
    this->lFPSTime = 0;

    //初始化SDL
    SDL_Init(SDL_INIT_VIDEO| SDL_INIT_TIMER| SDL_INIT_AUDIO);
    // 创建窗口
    //创建窗口
    m_window = SDL_CreateWindow("uContra",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                    CCFG::GAME_WIDTH,CCFG::GAME_HEIGHT,SDL_WINDOW_SHOWN);
    if(m_window == NULL){
        quitGame = true;
        std::cout<<"Error: "<<SDL_GetError()<<std::endl;
    }
    // 创建渲染
    m_renderer = SDL_CreateRenderer(m_window,-1,SDL_RENDERER_ACCELERATED);
    // 图标
    std::string fileName = "files/images/ico.bmp";
    SDL_Surface* loadedSurface = SDL_LoadBMP(fileName.c_str());
    SDL_SetWindowIcon(m_window,loadedSurface);
    SDL_FreeSurface(loadedSurface);
    // 设置全局事件信息
    mainEvent = new SDL_Event();
    // 加载音效文件
    
    // 加载地图文件
    
    // 显示界面，
    CCFG::getMM()->setActiveOption(m_renderer);
    CCFG::getLogo()->setImg("contra",m_renderer);
    CCFG::getText()->setFont(m_renderer,"font");


    // 加载并渲染主页面

    //其他部分的初始化
    this->keyLeft = this->keyRight = this->keyDown = this->keyUp = false;
    this->keyA = this->keyB = this->keyX = this->keyY = false;

    // 初始化按键配置
    CCFG::keyIDA = SDLK_j;
    CCFG::keyIDB = SDLK_k;
    CCFG::keyIDX = SDLK_l;
    CCFG::keyIDY = SDLK_i;

    CCFG::keyIDRight = SDLK_d;
    CCFG::keyIDLeft = SDLK_a;
    CCFG::keyIDUp = SDLK_w;
    CCFG::keyIDDown = SDLK_s;

    
}
Application::~Application(){
    delete mainEvent;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
void Application::mainloop(){
    lFPSTime = SDL_GetTicks();
    while(!quitGame && mainEvent->type != SDL_QUIT){
        frameTime = SDL_GetTicks();
        SDL_PollEvent(mainEvent);
        SDL_RenderClear(m_renderer);

        //设置菜单管理的背景颜色
        CCFG::getMM()->setBackgroundColor(m_renderer);
        SDL_RenderFillRect(m_renderer,NULL);

        //按键信息
        Input();
        //绘制
        Draw();
        //更新
        Update();
        
        //FPS 显示设置
        CCFG::getText()->Draw(m_renderer, "FPS:" + std::to_string(iNumOfFPS), CCFG::GAME_WIDTH - CCFG::getText()->getTextWidth("FPS:" + std::to_string(iNumOfFPS), 8) - 8, 5, 8);
        
        if(SDL_GetTicks()-1000>=lFPSTime){
            lFPSTime = SDL_GetTicks();
            iNumOfFPS = iFPS;
            iFPS = 0;
        }
        ++iFPS;


        SDL_RenderPresent(m_renderer);
        if(SDL_GetTicks() - frameTime<MIN_FRAME_TIME){
            SDL_Delay(MIN_FRAME_TIME - (SDL_GetTicks() - frameTime));
        }
    }
}

//按键信息
void Application::Input(){
    switch(CCFG::getMM()->getGameState()){
        case MenuManager::eMainMenu:
            InputMenu();
            break;
        case MenuManager::eAbout:
            break;
        case MenuManager::ePause:
            break;
        case MenuManager::eGameLoading:
            break;
        case MenuManager::eGame:
            break;
        case MenuManager::eOptions:
            break;
    }
}
//菜单输入
void Application::InputMenu(){
    if(mainEvent->type == SDL_KEYDOWN){
        switch(mainEvent->key.keysym.sym){
            //按下了向下的按键
            case SDLK_s: case SDLK_DOWN:
                if(!keyMenuPressed){
                    CCFG::getMM()->keyPressed(Menu::iDOWN_ITEM);
                    keyMenuPressed = true;
                }
                break;
            //按下的向上的按键
            case SDLK_w: case SDLK_UP:
                if(!keyMenuPressed){
                    CCFG::getMM()->keyPressed(Menu::iUP_ITEM);
                    keyMenuPressed = true;
                }
                break;
            //按下回车键
            case SDLK_KP_ENTER: case SDLK_RETURN:
                if(!keyMenuPressed){
                    CCFG::getMM()->enter();
                    keyMenuPressed = true;
                }
                break;
            //按下ESC按键
            case SDLK_ESCAPE:
                if(!keyMenuPressed){
                    CCFG::getMM()->escape();
                    keyMenuPressed = true;
                }
                break;
            //按下向左按键
            case SDLK_LEFT: case SDLK_d:
                if(!keyMenuPressed){
                    CCFG::getMM()->keyPressed(Menu::iLEFT_ITEM);
                    keyMenuPressed = true;
                }
                break;
            //按下向右按键
            case SDLK_RIGHT: case SDLK_a:
                if(!keyMenuPressed){
                    CCFG::getMM()->keyPressed(Menu::iRIGHT_ITEM);
                    keyMenuPressed = true;
                }
                break;
            default:
                break;
        }
    }
    if(mainEvent->type == SDL_KEYUP){
        switch(mainEvent->key.keysym.sym) {
			case SDLK_s: case SDLK_DOWN: case SDLK_w: case SDLK_UP: case SDLK_KP_ENTER: case SDLK_RETURN: case SDLK_ESCAPE: case SDLK_a: case SDLK_RIGHT: case SDLK_LEFT: case SDLK_d:
				keyMenuPressed = false;
				break;
			default:
				break;
		}
    }
}
//绘制
void Application::Draw(){
    CCFG::getMM()->Draw(m_renderer);
}

//更新
void Application::Update(){
    CCFG::getMM()->Update();
}