#pragma once
#include "DxLib.h"



class Game
{
private:
	enum class EScene { title, game, gameOver, gameClear };
	EScene me_now;



private:
	void Draw();

	void Process();





public:
	Game();
	~Game();


	void UpDate();
};

