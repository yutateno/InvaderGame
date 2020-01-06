#pragma once
#include "DxLib.h"
#include "InputKey.hpp"



class Game
{
private:
	enum class EScene { title, game, gameOver, gameClear };
	EScene me_now;



private:
	// �S�̂̕`��
	void Draw();
	// �^�C�g���̕`��
	void TitleDraw();
	// �Q�[���̕`��
	void GameDraw();
	// �Q�[���N���A�̕`��
	void GameClearDraw();
	// �Q�[���I�[�o�[�̕`��
	void GameOverDraw();

	// �S�̂̃v���Z�X
	void Process();
	// �^�C�g���̃v���Z�X
	void TitleProcess();
	// �Q�[���̃v���Z�X
	void GameProcess();
	// �Q�[���N���A�̃v���Z�X
	void GameClearProcess();
	// �Q�[���I�[�o�[�̃v���Z�X
	void GameOverProcess();





public:
	Game();
	~Game();


	void UpDate();
};

