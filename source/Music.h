# pragma once
# ifndef MUSIC_H
# define MUSIC_H
# include<vector>
# include<string>
# include<SDL2/SDL_mixer.h>

/**
 * Mix_Chunk结构代表一个样本,或者换句话说是一个声音效果.
 * Mix_Music结构代表的一段音乐,可以为在延长的时间周期,通常重复播放.
 * 
*/
class Music{
private:
    std::vector<Mix_Music*> vMusic;
    std::vector<Mix_Chunk*> vChunk;
    int iVolume;
    bool musicStopped;
public:
    Music();
    ~Music();

    enum eChunk{
        cALARM,
        cBOUNS,
        cBOMBING_1,
        cBOMBING_2,
        cBOMBING_3,
        cBOMBING_4,
        cBOMBING_5,
        cBOMBING_6,
        cBOMBING_7,
        cBOMBING_8,

        cHITSND0,
        cHITSND1,
        cHITSND2,
        cHITSND3,
        cHITSND4,
        cHITSND5,
        cHITSND6,

        cF_GUN,
        cL_GUN,
        cM_GUN,
        cN_GUN,
        cS_GUN,

        cP_1UP,
        cP_DEATH,
        cPAUSE,
        cLASER,
        cSTONE_LANDING,
        cENEMY
    };

    enum eMusic {
        mNOTHING,
        mSTAGE1,
        mSTAGE2,
        mSTAGE3,
        mSTAGE4,
        mSTAGE5,
        mSTAGE6,
        mSTAGE7,
        mSTAGE8,
        mBOSS1,
        mBOSS2,
        mBOSS3,
        mSTAGECLEAR1,
        mSTAGECLEAR2,
        mGAMEEND,
        mGAMEOVER
    };

    eMusic currentMusic;


    void changeMusic();
    // 播放音乐
    void PlayMusic();
    void PlayMusic(eMusic musicID,int loops=-1);
    void StopMusic();
    

    void PauseMusic();
    void PlayChunk(eChunk chunkID);

    Mix_Music* loadMusic(std::string fileName);
    Mix_Chunk* loadChunk(std::string fileName);

    void setVolume(int iVolume);
    int getVolume();
};
# endif
