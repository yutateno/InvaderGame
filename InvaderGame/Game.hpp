#pragma once
#include "DxLib.h"
#include "InputKey.hpp"



class Game
{
private:
	enum class EScene { title, game, gameOver, gameClear };
	EScene me_now;

	bool m_titleUI;

	bool m_gameOverUI;

	bool m_end;



private:
	// 全体の描画
	void Draw();
	// タイトルの描画
	void TitleDraw();
	// ゲームの描画
	void GameDraw();
	// ゲームクリアの描画
	void GameClearDraw();
	// ゲームオーバーの描画
	void GameOverDraw();

	// 全体のプロセス
	void Process();
	// タイトルのプロセス
	void TitleProcess();
	// ゲームのプロセス
	void GameProcess();
	// ゲームクリアのプロセス
	void GameClearProcess();
	// ゲームオーバーのプロセス
	void GameOverProcess();





public:
	Game();
	~Game();


	void UpDate();

	const bool GetEnd() const { return m_end; }
};

