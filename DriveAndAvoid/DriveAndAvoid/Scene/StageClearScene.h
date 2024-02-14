#pragma once

#include "SceneBase.h"

class StageClearScene : public SceneBase
{
private:
	int background_image; // �w�i�摜
	int text_image; //�e�L�X�g�摜

public:
	StageClearScene();
	virtual ~StageClearScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;
	virtual eSceneType GetNowScene() const override;
};

