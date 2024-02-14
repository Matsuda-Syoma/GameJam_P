#pragma once

#include "SceneBase.h"

class StageClearScene : public SceneBase
{
private:
	int background_image; // 背景画像
	int text_image; //テキスト画像

public:
	StageClearScene();
	virtual ~StageClearScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;
	virtual eSceneType GetNowScene() const override;
};

