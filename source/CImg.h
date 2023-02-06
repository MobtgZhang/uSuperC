# ifndef IMG_HEADERS
# define IMG_HEADERS

# include<SDL2/SDL.h>
# include<string>

class CImg{
private:
    SDL_Texture* tImg;
    SDL_Rect rRect;
public:
    CImg();
    CImg(std::string fileName,SDL_Renderer* rR);
    ~CImg();

    void Draw(SDL_Renderer* rR,int iXOffset,int iYOffset);
    void Draw(SDL_Renderer* rR,int iXOffset,int iYOffset,bool bRotate);
    void DrawVert(SDL_Renderer* rR,int iXOffset,int iYOffset);
    void Draw(SDL_Renderer* rR,SDL_Rect rCrop,SDL_Rect rRect);

    SDL_Texture* getImg();
    void setImg(std::string fileName,SDL_Renderer* rR,int cr=255,int cg=0,int cb=255);
    SDL_Rect getRect();
};

# endif
