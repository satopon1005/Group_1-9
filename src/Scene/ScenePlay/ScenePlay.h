#pragma once

#include "../../Objects/Player/Player.h"

class ScenePlay
{
private:
	Player player;

public:
	void InitPlay();
	void LoopPlay();
};