#pragma once

class Sounds
{


public:
	static int BGM_Game;
	static int BGM_Title;
	static int SE_Break;
	static int SE_Shoot;
	static int SE_Hit[3];
	static int SE_PlayerHit;


	static void LoadSounds();						// コンストラクタ
	~Sounds();						// デストラクタ
};