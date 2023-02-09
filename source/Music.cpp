# include "Music.h"

Music::Music(){
    //初始化SDL2音效
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    //加载Music文件

    vMusic.push_back(loadMusic("01 Contra (Title)"));
    vMusic.push_back(loadMusic("02 Introduction"));
    vMusic.push_back(loadMusic("03 Jungle Battle (Stage 1, 7)"));
    vMusic.push_back(loadMusic("04 Triumphant Return 1 (Stage Clear)"));
    vMusic.push_back(loadMusic("05 Maze Fortress 1 (Stage 2, 4)"));
    vMusic.push_back(loadMusic("06 Maze Fortress 2 (Stage 2, 4 Boss)"));
    vMusic.push_back(loadMusic("07 Waterfall of Bloodshed (Stage 3)"));
    vMusic.push_back(loadMusic("08 Fortress of Ice (Stage 5)"));
    vMusic.push_back(loadMusic("09 Fortress of Flame (Stage 6)"));
    vMusic.push_back(loadMusic("10 Horrible Heartbeat (Stage 8)"));
    vMusic.push_back(loadMusic("11 Triumphant Return 2 (All Stage Clear)"));
    vMusic.push_back(loadMusic("12 Sandinista (Ending)"));
    vMusic.push_back(loadMusic("13 Game Over"));


    //加载Chunk

    vChunk.push_back(loadChunk("airplane_motor"));
    vChunk.push_back(loadChunk("alarm"));
    vChunk.push_back(loadChunk("bombing0"));
    vChunk.push_back(loadChunk("bombing1"));
    vChunk.push_back(loadChunk("bombing2"));
    vChunk.push_back(loadChunk("bombing3"));
    vChunk.push_back(loadChunk("bombing4"));
    vChunk.push_back(loadChunk("bonus"));
    vChunk.push_back(loadChunk("f_gun"));
    vChunk.push_back(loadChunk("l_gun"));
    vChunk.push_back(loadChunk("m_gun"));
    vChunk.push_back(loadChunk("n_gun"));
    vChunk.push_back(loadChunk("s_gun"));
    vChunk.push_back(loadChunk("flame"));
    vChunk.push_back(loadChunk("hitsnd0"));
    vChunk.push_back(loadChunk("hitsnd1"));
    vChunk.push_back(loadChunk("hitsnd2"));
    vChunk.push_back(loadChunk("p_1up"));
    vChunk.push_back(loadChunk("p_death"));
    vChunk.push_back(loadChunk("p_landing"));
    vChunk.push_back(loadChunk("p_shock"));
    vChunk.push_back(loadChunk("pause"));
    vChunk.push_back(loadChunk("pipebomb"));
    vChunk.push_back(loadChunk("robot_landing"));
    vChunk.push_back(loadChunk("stone_landing"));

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

