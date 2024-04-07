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

		if(scene_play.StepPlay())
			m_current_scene_ID = SCENE_FINPLAY;

		scene_play.DrawPlay();

		break;
	}
	case SCENE_FINPLAY: {

		scene_play.FinPlay();

		if(scene_play.GetPlayerDeayhFlag())
			m_current_scene_ID = SCENE_INITGAMEOVER;
		else
			m_current_scene_ID = SCENE_INITCLEAR;
		break;
	}
	//----------------------------------------------------------------------------------
	case SCENE_INITGAMEOVER: {
		scene_gameover.InitGameOver();
		m_current_scene_ID = SCENE_LOOPGAMEOVER;
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
	}
	case SCENE_LOOPCLEAR: {
		if (scene_clear.StepClear())
			m_current_scene_ID = SCENE_FINCLEAR;

		scene_clear.DrawClear();

		break;
	}
	case SCENE_FINCLEAR: {

		m_current_scene_ID = SCENE_INITTITLE;
	}
	}
}