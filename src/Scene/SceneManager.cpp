#include "DxLib.h"
#include "SceneManager.h"
#include "../../SceneTitle.h"

SceneManager::SceneManager()
{
	m_current_scene_ID = SCENE_INITPLAY;
}

SceneManager::~SceneManager()
{

}

void SceneManager::Main()
{
	switch (m_current_scene_ID) {
	case SCENE_INITTITLE: {
	    

		m_current_scene_ID = SCENE_LOOPTITLE;
		break;
	}
	case SCENE_LOOPTITLE: {

		break;
	}
	case SCENE_FINTITLE: {

		m_current_scene_ID = SCENE_INITPLAY;
		break;
	}
	//---------------------------------------------------------------------------------
	case SCENE_INITPLAY: {

		sceneplay.InitPlay();

		m_current_scene_ID = SCENE_LOOPPLAY;
		break;
	}
	case SCENE_LOOPPLAY: {

		sceneplay.LoopPlay();

		break;
	}
	case SCENE_FINPLAY: {

		break;
	}
	//----------------------------------------------------------------------------------
	case SCENE_INITGAMEOVER: {

		m_current_scene_ID = SCENE_LOOPGAMEOVER;
		break;
	}
	case SCENE_LOOPGAMEOVER: {

		break;
	}
	case SCENE_FINGAMEOVER: {

		m_current_scene_ID = SCENE_INITTITLE;
		break;
	}
	//----------------------------------------------------------------------------------
	case SCENE_INITCLEAR: {

		m_current_scene_ID = SCENE_LOOPCLEAR;
		break;
	}
	case SCENE_LOOPCLEAR: {

		break;
	}
	case SCENE_FINCLEAR: {

		m_current_scene_ID = SCENE_INITTITLE;
		break;
	}
	}
}