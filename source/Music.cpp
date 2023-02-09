# include "Music.h"

Music::Music(){
    //初始化SDL2音效
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    //加载Music文件
    vMusic.push_back(loadMusic("Stage 1"));
    vMusic.push_back(loadMusic("Stage 2"));
    vMusic.push_back(loadMusic("Stage 3"));
    vMusic.push_back(loadMusic("Stage 4"));
    vMusic.push_back(loadMusic("Stage 5"));
    vMusic.push_back(loadMusic("Stage 6"));
    vMusic.push_back(loadMusic("Stage 7"));
    vMusic.push_back(loadMusic("Stage 8"));
    vMusic.push_back(loadMusic("Boss 1"));
    vMusic.push_back(loadMusic("Boss 2"));
    vMusic.push_back(loadMusic("Boss 3"));
    vMusic.push_back(loadMusic("Stage Clear 1"));
    vMusic.push_back(loadMusic("Stage Clear 2"));
    vMusic.push_back(loadMusic("End"));
    vMusic.push_back(loadMusic("Game Over"));


    //加载Chunk

    vChunk.push_back(loadChunk("alarm"));
    vChunk.push_back(loadChunk("bonus"));
    vChunk.push_back(loadChunk("boom1"));
    vChunk.push_back(loadChunk("boom2"));
    vChunk.push_back(loadChunk("boom3"));
    vChunk.push_back(loadChunk("boom4"));
    vChunk.push_back(loadChunk("boom5"));
    vChunk.push_back(loadChunk("boom6"));
    vChunk.push_back(loadChunk("boom7"));
    vChunk.push_back(loadChunk("boom8"));
    vChunk.push_back(loadChunk("hit0"));
    vChunk.push_back(loadChunk("hit1"));
    vChunk.push_back(loadChunk("hit2"));
    vChunk.push_back(loadChunk("hit3"));
    vChunk.push_back(loadChunk("hit4"));
    vChunk.push_back(loadChunk("hit5"));
    vChunk.push_back(loadChunk("hit6"));
    vChunk.push_back(loadChunk("f_gun"));
    vChunk.push_back(loadChunk("l_gun"));
    vChunk.push_back(loadChunk("m_gun"));
    vChunk.push_back(loadChunk("n_gun"));
    vChunk.push_back(loadChunk("s_gun"));
    vChunk.push_back(loadChunk("p_1up"));
    vChunk.push_back(loadChunk("p_death"));
    vChunk.push_back(loadChunk("pause"));
    vChunk.push_back(loadChunk("laser"));
    vChunk.push_back(loadChunk("stone_landing"));
    vChunk.push_back(loadChunk("enemy"));

    setVolume(100);
	this->currentMusic = mNOTHING;
}

//加载Music
 
Mix_Music* Music::loadMusic(std::string fileName){
    fileName = "files/sounds/" + fileName + ".mp3";
    return Mix_LoadMUS(fileName.c_str());
}

//加载Chunk
Mix_Chunk* Music::loadChunk(std::string fileName){
    fileName = "files/sounds/" + fileName + ".wav";
    return Mix_LoadWAV(fileName.c_str());
}

Music::~Music(){
    for(unsigned int k=0;k<vMusic.size();k++){
        Mix_FreeMusic(vMusic[k]);
    }
    vMusic.clear();

    for(unsigned int k=0;k<vChunk.size();k++){
        Mix_FreeChunk(vChunk[k]);
    }
    vChunk.clear();
}

void Music::setVolume(int iVolume){
    this->iVolume = iVolume;
    Mix_VolumeMusic(iVolume);
}

int Music::getVolume(){
    return this->iVolume;
}

void Music::PlayMusic(){
    if(currentMusic!=mNOTHING){
        Mix_PlayMusic(vMusic[currentMusic-1],-1);
        musicStopped = false;
    }else{
        StopMusic();
    }
}


void Music::PlayMusic(eMusic musicID,int loops){
    if(musicID!=mNOTHING){
        Mix_PlayMusic(vMusic[musicID-1],loops);
        musicStopped = false;
        currentMusic = musicID;
    }else{
        StopMusic();
        currentMusic = mNOTHING;
    }
}

void Music::changeMusic(){

}

void Music::PauseMusic(){
    if(Mix_PausedMusic()){
        Mix_ResumeMusic();
        musicStopped = false;
    }else{
        Mix_PauseMusic();
        musicStopped = true;
    }
}


void Music::StopMusic(){
    if(!musicStopped){
        Mix_HaltMusic();
        musicStopped = true;
    }
}

void Music::PlayChunk(eChunk chunkID){
    Mix_VolumeChunk(vChunk[chunkID],iVolume);
    Mix_PlayChannel(-1,vChunk[chunkID],0);
}

