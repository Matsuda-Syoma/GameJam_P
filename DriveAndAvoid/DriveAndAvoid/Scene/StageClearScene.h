#pragma once

#include "SceneBase.h"

class StageClearScene : public SceneBase
{
private:
	int background_image; // ”wŒi‰æ‘œ

public:
	StageClearScene();
	virtual ~StageClearScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;
	virtual eSceneType GetNowScene() const override;
};

