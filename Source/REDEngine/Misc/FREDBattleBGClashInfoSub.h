#pragma once

class USoundCue;
class UParticleSystem;

struct FREDBattleBGClashEffectData
{
	FName Name;                                                    
	UParticleSystem* PSTemplate;                                              
	USoundCue* SoundCue;                                                
};

struct FREDBattleBGClashInfoSub
{
	FName EventName;                                               
	int32 Offset;                                                  
	int32 Area;
	TArray<FREDBattleBGClashEffectData> EffectList;                                              
};

struct FREDBattleBGClashInfo
{
	TArray<FREDBattleBGClashInfoSub> ClashInfos;                                              
};