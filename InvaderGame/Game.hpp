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
	/// プレイヤー---------------------------------

	int m_health;

	int m_playerX;

	const int m_playerY = 850;


	// 弾------------------------------------------

	struct SGun
	{
		bool m_isAlive;

		int m_areaX, m_areaY;
	};
	SGun ms_playerGun[7];

	bool GunCheckCircleColl(const int t_centerX, const int t_centerY, const SGun t_gun, const int t_circleR = 10);

	bool GunCheckBoxColl(const int t_centerX, const int t_centerY, const SGun t_gun);


	/// 雑魚敵-------------------------------------

	enum class EType { bigCircle, circle, box, triangle };
	void TypeDraw(const EType t_type, const int t_centerAreaX, const int t_centerAreaY, const int t_size = 10);

	struct SEnemy
	{
		EType m_type;

		int m_areaX, m_areaY;

		bool m_isAlive;

		SGun ms_gun;

		int m_gunShotTime;
	};
	SEnemy ms_enemyArray[49];

	int m_enemyMoveTime;

	const int m_enemyMoveSide = 10;

	bool m_isEnemyMoveRight;

	bool m_isEnemyMoveDown;

	bool m_isSmallEnemyEnd;


	/// ボス--------------------------------------

	int m_enemyBossAreaY;

	int m_enemyBossHealth;

	int m_enemyBossCircle;

	int m_enemyBossNoDamageEffect;


	/// その他-----------------------------------

	int m_score;

	int m_preScore;

	int m_preHealth;

	int m_startTimer;



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


	void GameInit();





public:
	Game();
	~Game();


	void UpDate();

	const bool GetEnd() const { return m_isEnd; }
};

