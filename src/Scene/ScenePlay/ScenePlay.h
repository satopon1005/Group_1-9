#pragma once

#include "../../Objects/Player/Player.h"
#include "../../CountTime/CountTime.h"

class ScenePlay
{
private:
	Player player;
	CountTime count_time;

public:
	void InitPlay();
	void LoopPlay();
};