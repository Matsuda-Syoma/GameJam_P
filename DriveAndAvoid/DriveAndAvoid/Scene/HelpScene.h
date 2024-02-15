#pragma once

#include "SceneBase.h"

class HelpScene : public SceneBase
{
private:
	int background_image;	// �w�i�摜
	int text_image; //�e�L�X�g�摜
	int setumei_image;

public:
	HelpScene();
	virtual ~HelpScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;
	virtual eSceneType GetNowScene() const override;
};

