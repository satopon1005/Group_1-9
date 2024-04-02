#pragma once
#include "../Objects/Player/Player.h"

enum SceneNumber
{
	SCENE_INITTITLE,
	SCENE_LOOPTITLE,
	SCENE_FINTITLE,

	SCENE_INITPLAY,
	SCENE_LOOPPLAY,
	SCENE_FINPLAY,

	SCENE_INITGAMEOVER,
	SCENE_LOOPGAMEOVER,
	SCENE_FINGAMEOVER,

	SCENE_INITCLEAR,
	SCENE_LOOPCLEAR,
	SCENE_FINCLEAR,
};

class SceneManager
{
private:
	int m_current_scene_ID;
	Player player;

public:
	SceneManager();
	~SceneManager();

	void Main();
};