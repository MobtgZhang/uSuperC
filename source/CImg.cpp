# include "CImg.h"
# include<SDL2/SDL_image.h>

CImg::CImg(){}
CImg::CImg(std::string fileName,SDL_Renderer* rR){
    setImg(fileName,rR);
}
CImg::~CImg(){
    SDL_DestroyTexture(tImg);
}

void CImg::Draw(SDL_Renderer* rR,int iXOffset,int iYOffset){
    rRect.x = iXOffset;
    rRect.y = iYOffset;

    SDL_RenderCopy(rR,tImg,NULL,&rRect);
}

void CImg::Draw(SDL_Renderer* rR,int iXOffset,int iYOffset,bool bRotate){
    rRect.x = iXOffset;
    rRect.y = iYOffset;

    if(!bRotate){
        SDL_RenderCopy(rR,tImg,NULL,&rRect);
    }else{
        SDL_RenderCopyEx(rR,tImg,NULL,&rRect,180.0,NULL,SDL_FLIP_VERTICAL);
    }
}

void CImg::DrawVert(SDL_Renderer* rR,int iXOffset,int iYOffset){
    rRect.x = iXOffset;
    rRect.y = iYOffset;

    SDL_RenderCopyEx(rR,tImg,NULL,&rRect,180.0,NULL,SDL_FLIP_HORIZONTAL);
}

void CImg::Draw(SDL_Renderer* rR,SDL_Rect rCrop,SDL_Rect rRect){
    SDL_RenderCopy(rR,tImg,&rCrop,&rRect);
}

void CImg::setImg(std::string fileName,SDL_Renderer* rR,int cr,int cg,int cb){
    fileName = "files/images/" + fileName + ".bmp";
	SDL_Surface* loadedSurface = SDL_LoadBMP(fileName.c_str());
    SDL_SetColorKey(loadedSurface,SDL_TRUE,SDL_MapRGB(loadedSurface->format,cr,cg,cb));

    tImg = SDL_CreateTextureFromSurface(rR,loadedSurface);
    int iWidth,iHeight;

    SDL_QueryTexture(tImg,NULL,NULL,&iWidth,&iHeight);

    rRect.x = 0;
    rRect.y = 0;
    rRect.w = iWidth;
    rRect.h = iHeight;
    SDL_FreeSurface(loadedSurface);
}

SDL_Texture* CImg::getImg(){
    return tImg;
}

SDL_Rect CImg::getRect(){
    return rRect;
}
