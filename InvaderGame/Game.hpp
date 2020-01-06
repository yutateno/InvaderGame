#pragma once
#include "DxLib.h"
#include "InputKey.hpp"
#include <random>



class Game
{
private:
	enum class EScene { title, game, gameOver, gameClear };
	EScene me_now;

	bool m_isTitleUI;

	bool m_isGameOverUI;

	bool m_isEnd;


private:
	/// プレイヤー

	int m_health;

	int m_playerX;

	const int m_playerY = 850;


	// 弾

	bool m_gunAlive;

	int m_gunAreaX, m_gunAreaY;

	bool GunCheckCircleColl(const int t_centerX, const int t_centerY);

	bool GunCheckBoxColl(const int t_centerX, const int t_centerY);


	/// 雑魚敵

	enum class EType { bigCircle, circle, box, triangle };
	void TypeDraw(const EType t_type, const int t_centerAreaX, const int t_centerAreaY, const int t_size = 10);

	struct SEnemy
	{
		EType m_type;

		int m_areaX, m_areaY;

		bool m_isAlive;
	};
	SEnemy ms_enemyArray[49];

	int m_enemyMoveTime;

	const int m_enemyMoveSide = 10;

	bool m_isEnemyMoveRight;

	bool m_isEnemyMoveDown;


	/// ボス

	bool m_isEnemyBosAlive;

	int m_enemyBosAreaY;


	/// その他

	int m_score;



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

	const bool GetEnd() const { return m_isEnd; }
};

