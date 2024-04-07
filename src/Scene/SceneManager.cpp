#include "DxLib.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{
	m_current_scene_ID = SCENE_INITTITLE;
}

SceneManager::~SceneManager()
{

}

void SceneManager::Main()
{
	switch (m_current_scene_ID) {
	case SCENE_INITTITLE: {
		scene_title.InitTitle();

		m_current_scene_ID = SCENE_LOOPTITLE;
		break;
	}
	case SCENE_LOOPTITLE: {

		if(scene_title.StepTitle())
			m_current_scene_ID = SCENE_FINTITLE;

		scene_title.DrawTitle();

		break;
	}
	case SCENE_FINTITLE: {

		m_current_scene_ID = SCENE_INITPLAY;
	}
	//---------------------------------------------------------------------------------
	case SCENE_INITPLAY: {

		scene_play.InitPlay();

		m_current_scene_ID = SCENE_LOOPPLAY;
	}
	case SCENE_LOOPPLAY: {

		scene_play.LoopPlay();
		scene_play.DrawPlay();

		break;
	}
	case SCENE_FINPLAY: {

		break;
	}
	//----------------------------------------------------------------------------------
	case SCENE_INITGAMEOVER: {
		scene_gameover.InitGameOver();
		m_current_scene_ID = SCENE_LOOPGAMEOVER;
		break;
	}
	case SCENE_LOOPGAMEOVER: {
		if (scene_gameover.StepGameOver())
			m_current_scene_ID = SCENE_FINCLEAR;

		scene_gameover.DrawGameOver();
		break;
	}
	case SCENE_FINGAMEOVER: {

		m_current_scene_ID = SCENE_INITTITLE;
		break;
	}
	//----------------------------------------------------------------------------------
	case SCENE_INITCLEAR: {
		scene_clear.InitClear();
		m_current_scene_ID = SCENE_LOOPCLEAR;
		break;
	}
	case SCENE_LOOPCLEAR: {
		if (scene_clear.StepClear())
			m_current_scene_ID = SCENE_FINCLEAR;

		scene_clear.DrawClear();

		break;
	}
	case SCENE_FINCLEAR: {

		m_current_scene_ID = SCENE_INITTITLE;
		break;
	}
	}
}