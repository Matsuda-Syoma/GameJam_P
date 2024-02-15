#include "Sounds.h"
#include "DxLib.h"
bool Sounds::isload;
int Sounds::BGM_Game;
int Sounds::BGM_Title;
int Sounds::SE_Break;
int Sounds::SE_Shoot;
int Sounds::SE_Hit[3];
int Sounds::SE_PlayerHit;
void Sounds::LoadSounds() {
	if (!isload) {
		isload = true;
		BGM_Game = LoadSoundMem("Resource/sounds/BGM_Trip.wav");
		BGM_Title = LoadSoundMem("Resource/sounds/BGM_Trip.wav");
		SE_Break = LoadSoundMem("Resource/sounds/SE_Break.mp3");
		SE_Shoot = LoadSoundMem("Resource/sounds/SE_Shoot.mp3");
		for (int i = 0; i < 3; i++)
		{
			SetCreateSoundPitchRate(500.0f * (i - 1));
			SE_Hit[i] = LoadSoundMem("Resource/sounds/SE_Hit.mp3");
		}
		SetCreateSoundPitchRate(0);
		SE_PlayerHit = LoadSoundMem("Resource/sounds/SE_PlayerHit.mp3");
	}
}

Sounds::~Sounds()
{
	DeleteSoundMem(BGM_Game);
	DeleteSoundMem(BGM_Title);
	DeleteSoundMem(SE_Break);
	DeleteSoundMem(SE_Shoot);
	for (int i = 0; i < 3; i++)
	{
		DeleteSoundMem(SE_Hit[i]);
	}
	DeleteSoundMem(SE_PlayerHit);
}
