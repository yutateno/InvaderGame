#include "Game.hpp"



/// ------------------------------------------------------------------------------------------------------------
bool Game::GunCheckCircleColl(const int t_centerX, const int t_centerY, const SGun t_gun)
{
	const float left = static_cast<float>(t_centerX - 10);
	const float top = static_cast<float>(t_centerY - 10);
	const float right = static_cast<float>(t_centerX + 10);
	const float bottom = static_cast<float>(t_centerY + 10);

	// DrawBox(m_gunAreaX - 2, m_gunAreaY, m_gunAreaX + 2, m_gunAreaY + 5, GetColor(255, 255, 255), true);
	const float gunLeft = static_cast<float>(t_gun.m_areaX - 2);
	const float gunTop = static_cast<float>(t_gun.m_areaY);
	const float gunRight = static_cast<float>(t_gun.m_areaX + 2);
	const float gunBottom = static_cast<float>(t_gun.m_areaY + 5);

	if ((gunRight > left) && (gunLeft < right))
	{
		if ((gunBottom > top) && (gunTop < bottom))
		{
			return true;
		}
	}

	return false;
}



/// ------------------------------------------------------------------------------------------------------------
bool Game::GunCheckBoxColl(const int t_centerX, const int t_centerY, const SGun t_gun)
{
	const float centerX = static_cast<float>(t_centerX);
	const float centerY = static_cast<float>(t_centerY);
	const float centerR = 10.0f;

	// DrawBox(m_gunAreaX - 2, m_gunAreaY, m_gunAreaX + 2, m_gunAreaY + 5, GetColor(255, 255, 255), true);
	const float gunLeft = static_cast<float>(t_gun.m_areaX - 2);
	const float gunTop = static_cast<float>(t_gun.m_areaY);
	const float gunRight = static_cast<float>(t_gun.m_areaX + 2);
	const float gunBottom = static_cast<float>(t_gun.m_areaY + 5);

	bool nResult = false;

	// 四角形の四辺に対して円の半径分だけ足したとき円が重なっていたら
	if ((centerX > gunLeft - centerR) && (centerX < gunRight + centerR) &&
		(centerY > gunTop - centerR) && (centerY < gunBottom + centerR))
	{
		nResult = true;
		float fl = centerR * centerR;


		// 左
		if (centerX < gunLeft)
		{
			// 左上
			if ((centerY < gunTop))
			{
				float dx = centerX - gunLeft;
				float dy = centerY - gunTop;

				float distanceSqrf = (dx * dx) + (dy * dy);

				// 重なっていない
				if (distanceSqrf >= fl)
				{
					nResult = false;
				}
			}
			else
			{
				// 左下
				if ((centerY > gunBottom))
				{
					float dx = centerX - gunLeft;
					float dy = centerY - gunBottom;

					float distanceSqrf = (dx * dx) + (dy * dy);

					// 重なっていない
					if (distanceSqrf >= fl)
					{
						nResult = false;
					}
				}
			}
		}
		else
		{
			// 右
			if (centerX > gunRight)
			{
				// 右上
				if ((centerY < gunTop))
				{
					float dx = centerX - gunRight;
					float dy = centerY - gunTop;

					float distanceSqrf = (dx * dx) + (dy * dy);

					// 重なっていない
					if (distanceSqrf >= fl)
					{
						nResult = false;
					}
				}
				else
				{
					// 右下
					if ((centerY > gunBottom))
					{
						float dx = centerX - gunRight;
						float dy = centerY - gunBottom;

						float distanceSqrf = (dx * dx) + (dy * dy);

						// 重なっていない
						if (distanceSqrf >= fl)
						{
							nResult = false;
						}
					}
				}
			}
		}
	}

	return nResult;
}



/// ------------------------------------------------------------------------------------------------------------
void Game::TypeDraw(const EType t_type, const int t_centerAreaX, const int t_centerAreaY, const int t_size)
{
	switch (t_type)
	{
	case EType::bigCircle:
		DrawCircleAA(static_cast<float>(t_centerAreaX), static_cast<float>(t_centerAreaY)
			, static_cast<float>(t_size * 3), 32, GetColor(255, 255, 255), true);
		break;

		
	case EType::box:
		DrawBoxAA(static_cast<float>(t_centerAreaX - t_size), static_cast<float>(t_centerAreaY - t_size)
			, static_cast<float>(t_centerAreaX + t_size), static_cast<float>(t_centerAreaY + t_size), GetColor(255, 255, 255), true);
		break;


	case EType::circle:
		DrawCircleAA(static_cast<float>(t_centerAreaX), static_cast<float>(t_centerAreaY)
			, static_cast<float>(t_size), 32, GetColor(255, 255, 255), true);
		break;


	case EType::triangle:
		DrawTriangleAA(static_cast<float>(t_centerAreaX - t_size), static_cast<float>(t_centerAreaY + t_size)
			, static_cast<float>(t_centerAreaX), static_cast<float>(t_centerAreaY - t_size)
			, static_cast<float>(t_centerAreaX + t_size), static_cast<float>(t_centerAreaY + t_size), GetColor(255, 255, 255), true);
		break;


	default:
		break;
	}
}



/// ------------------------------------------------------------------------------------------------------------
void Game::Draw()
{
	switch (me_now)
	{
	case EScene::title:
		TitleDraw();
		break;


	case EScene::game:
		GameDraw();
		break;


	case EScene::gameClear:
		GameDraw();
		GameClearDraw();
		break;


	case EScene::gameOver:
		GameDraw();
		GameOverDraw();
		break;


	default:
		break;
	}
}



/// ------------------------------------------------------------------------------------------------------------
void Game::TitleDraw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Title");

	if (m_isTitleUI)
	{
		DrawBoxAA(960 / 2 - 10, 960 / 2 - 2, 960 / 2 + 60, 960 / 2 + 20, GetColor(255, 255, 255), false);
	}
	else
	{
		DrawBoxAA(960 / 2 - 10, 960 / 2 - 2, 960 / 2 + 60, 960 / 2 + 20, GetColor(255, 0, 0), false);
	}
	DrawFormatString(960 / 2, 960 / 2, GetColor(255, 255, 255), "かいし");

	if (m_isTitleUI)
	{
		DrawBoxAA(960 / 2 - 10, 960 / 2 + 64 - 2, 960 / 2 + 60, 960 / 2 + 64 + 20, GetColor(255, 0, 0), false);
	}
	else
	{
		DrawBoxAA(960 / 2 - 10, 960 / 2 + 64 - 2, 960 / 2 + 60, 960 / 2 + 64 + 20, GetColor(255, 255, 255), false);
	}
	DrawFormatString(960 / 2, 960 / 2 + 64, GetColor(255, 255, 255), "やめる");

	DrawFormatString(960 - 110, 960 - 64, GetColor(255, 255, 255), "Zきーをおせ");
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameDraw()
{
	if (me_now == EScene::game)
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Game");
	}


	// 全体枠
	DrawBoxAA(30, 30, 930, 930, GetColor(255, 255, 255), false);


	// 残基
	DrawFormatString(35, 930 - 60, GetColor(255, 255, 255), "ざんき：%d", m_health - 1);
	if (m_health == 3)
	{
		TypeDraw(EType::triangle, 50, 930 - 30, 8);
		TypeDraw(EType::triangle, 70, 930 - 30, 8);
	}
	else if (m_health == 2)
	{
		TypeDraw(EType::triangle, 50, 930 - 30);
	}


	// スコア
	DrawFormatString(40, 80, GetColor(255, 255, 255), "すこあ\n%05d", m_score);


	// 前回スコア
	DrawFormatString(960 - 160, 80, GetColor(255, 255, 255), "前回スコア\n%05d\n前回ヘルス\n%05d", m_preScore, m_preHealth);


	// ゲーム枠
	DrawBoxAA(180, 60, 960 - 180, 960 - 60, GetColor(255, 255, 255), false);


	// 敵大将
	TypeDraw(EType::bigCircle, 480, m_enemyBosAreaY);


	// 雑魚
	for (int number = 0; number != 49; ++number)
	{
		if (ms_enemyArray[number].m_isAlive)
		{
			TypeDraw(ms_enemyArray[number].m_type, ms_enemyArray[number].m_areaX, ms_enemyArray[number].m_areaY);
		}
	}


	// プレイヤー
	TypeDraw(EType::triangle, m_playerX, m_playerY);


	// 敵の弾
	for (int number = 0; number != 49; ++number)
	{
		if (ms_enemyArray[number].ms_gun.m_isAlive)
		{
			DrawBox(ms_enemyArray[number].ms_gun.m_areaX - 2, ms_enemyArray[number].ms_gun.m_areaY
				, ms_enemyArray[number].ms_gun.m_areaX + 2, ms_enemyArray[number].ms_gun.m_areaY + 5, GetColor(255, 255, 255), true);
		}
	}


	// プレイヤーの弾
	for (int i = 0; i != 7; ++i)
	{
		if (ms_playerGun[i].m_isAlive)
		{
			DrawBox(ms_playerGun[i].m_areaX - 2, ms_playerGun[i].m_areaY, ms_playerGun[i].m_areaX + 2, ms_playerGun[i].m_areaY + 5, GetColor(255, 200, 200), true);
		}
	}
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameClearDraw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameClear");

	DrawBoxAA(960 / 2 - 10, 960 / 2 - 2, 960 / 2 + 120, 960 / 2 + 20, GetColor(255, 0, 0), false);
	DrawFormatString(960 / 2, 960 / 2, GetColor(255, 255, 255), "たいとるもどる");

	DrawFormatString(960 - 110, 960 - 64, GetColor(255, 255, 255), "Zきーをおせ");
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameOverDraw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameOver");

	if (m_isGameOverUI)
	{
		DrawBoxAA(960 / 2 - 10, 960 / 2 - 2, 960 / 2 + 100, 960 / 2 + 20, GetColor(255, 255, 255), false);
	}
	else
	{
		DrawBoxAA(960 / 2 - 10, 960 / 2 - 2, 960 / 2 + 100, 960 / 2 + 20, GetColor(255, 0, 0), false);
	}
	DrawFormatString(960 / 2, 960 / 2, GetColor(255, 255, 255), "やりなおす");

	if (m_isGameOverUI)
	{
		DrawBoxAA(960 / 2 - 10, 960 / 2 + 64 - 2, 960 / 2 + 120, 960 / 2 + 64 + 20, GetColor(255, 0, 0), false);
	}
	else
	{
		DrawBoxAA(960 / 2 - 10, 960 / 2 + 64 - 2, 960 / 2 + 120, 960 / 2 + 64 + 20, GetColor(255, 255, 255), false);
	}
	DrawFormatString(960 / 2, 960 / 2 + 64, GetColor(255, 255, 255), "たいとるもどる");

	DrawFormatString(960 - 110, 960 - 64, GetColor(255, 255, 255), "Zきーをおせ");
}



/// ------------------------------------------------------------------------------------------------------------
void Game::Process()
{
	switch (me_now)
	{
	case EScene::title:
		TitleProcess();
		break;


	case EScene::game:
		GameProcess();
		break;


	case EScene::gameClear:
		GameClearProcess();
		break;


	case EScene::gameOver:
		GameOverProcess();
		break;


	default:
		break;
	}
}



/// ------------------------------------------------------------------------------------------------------------
void Game::TitleProcess()
{
	if (KeyData::Get(KEY_INPUT_Z) == 1)
	{
		if(m_isTitleUI)
		{
			m_isEnd = true;
		}
		else
		{
			GameInit();
			me_now = EScene::game;
		}
	}


	if (KeyData::Get(KEY_INPUT_UP) == 1)
	{
		m_isTitleUI = false;
	}
	if (KeyData::Get(KEY_INPUT_DOWN) == 1)
	{
		m_isTitleUI = true;
	}
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameProcess()
{
	// プレイヤー左右
	if (KeyData::Get(KEY_INPUT_RIGHT) >= 1)
	{
		if (m_playerX < 960 - 230)
		{
			m_playerX += 2;
		}
	}
	if (KeyData::Get(KEY_INPUT_LEFT) >= 1)
	{
		if (m_playerX > 230)
		{
			m_playerX -= 2;
		}
	}

	
	// プレイヤーの弾の生成
	if (KeyData::Get(KEY_INPUT_G) == 1)
	{
		for (int i = 0; i != 7; ++i)
		{
			if (!ms_playerGun[i].m_isAlive)
			{
				ms_playerGun[i].m_isAlive = true;
				ms_playerGun[i].m_areaX = m_playerX;
				ms_playerGun[i].m_areaY = m_playerY;
				break;
			}
		}
	}


	// プレイヤーの弾の動き
	for (int k = 0; k != 7; ++k)
	{
		if (ms_playerGun[k].m_isAlive)
		{
			ms_playerGun[k].m_areaY -= 5;
			if (ms_playerGun[k].m_areaY < 60)
			{
				ms_playerGun[k].m_isAlive = false;
				continue;
			}

			int number = 0;
			for (int i = 0; i != 7; ++i)
			{
				for (int j = 0; j != 7; ++j)
				{
					if (!ms_enemyArray[number].m_isAlive)
					{
						number++;
						continue;
					}


					if (ms_enemyArray[number].m_type == EType::box)
					{
						if (GunCheckBoxColl(ms_enemyArray[number].m_areaX, ms_enemyArray[number].m_areaY, ms_playerGun[k]))
						{
							m_score += 10;
							ms_enemyArray[number].m_isAlive = false;
							ms_playerGun[k].m_isAlive = false;
						}
					}
					else if (ms_enemyArray[number].m_type == EType::circle)
					{
						if (GunCheckCircleColl(ms_enemyArray[number].m_areaX, ms_enemyArray[number].m_areaY, ms_playerGun[k]))
						{
							m_score += 10;
							ms_enemyArray[number].m_isAlive = false;
							ms_playerGun[k].m_isAlive = false;
						}
					}
					number++;
				}
			}
		}
	}


	// 敵の動きカウント
	m_enemyMoveTime++;


	// 敵を左右に動かす
	if (m_enemyMoveTime % m_enemyMoveSide == 0 && m_enemyMoveTime > 0)
	{
		int number = 0;
		for (int i = 0; i != 7; ++i)
		{
			for (int j = 0; j != 7; ++j)
			{
				if (m_isEnemyMoveRight)
				{
					ms_enemyArray[number].m_areaX += 20;
				}
				else
				{
					ms_enemyArray[number].m_areaX -= 20;
				}
				number++;
			}
		}


		// 左端のものが左上限に行ったら
		if (ms_enemyArray[0].m_areaX <= 230)
		{
			m_isEnemyMoveRight = true;
			m_isEnemyMoveDown = true;
			m_enemyMoveTime = -(m_enemyMoveSide * 2);
		}


		// 右端のものが右上限に行ったら
		if (ms_enemyArray[6].m_areaX >= 960 - 230)
		{
			m_isEnemyMoveRight = false;
			m_isEnemyMoveDown = true;
			m_enemyMoveTime = -(m_enemyMoveSide * 2);
		}
	}


	// 敵を下げさせる
	if (m_isEnemyMoveDown && m_enemyMoveTime == -m_enemyMoveSide)
	{
		int number = 0;
		for (int i = 0; i != 7; ++i)
		{
			for (int j = 0; j != 7; ++j)
			{
				ms_enemyArray[number].m_areaY += 25;
				number++;
			}
		}
		m_enemyBosAreaY += 25;
		if (m_isEnemyMoveDown) m_isEnemyMoveDown = false;
	}


	// 敵の弾
	for (int number = 0; number != 49; ++number)
	{
		// 敵が弾を撃っていたら
		if (ms_enemyArray[number].ms_gun.m_isAlive)
		{
			ms_enemyArray[number].ms_gun.m_areaY += 5;
			if (ms_enemyArray[number].ms_gun.m_areaY > 960 - 60 - 5)
			{
				ms_enemyArray[number].ms_gun.m_isAlive = false;
				continue;
			}
		}


		// 敵が死んでいなかったら
		if (ms_enemyArray[number].m_isAlive)
		{
			if (!ms_enemyArray[number].ms_gun.m_isAlive && m_enemyMoveTime % ms_enemyArray[number].m_gunShotTime == 0 && m_enemyMoveTime > 0)
			{
				ms_enemyArray[number].ms_gun.m_isAlive = true;
				ms_enemyArray[number].ms_gun.m_areaX = ms_enemyArray[number].m_areaX;
				ms_enemyArray[number].ms_gun.m_areaY = ms_enemyArray[number].m_areaY;
			}
		}


		// 敵に当たったかどうか
		if (GunCheckCircleColl(m_playerX, m_playerY, ms_enemyArray[number].ms_gun))
		{
			ms_enemyArray[number].ms_gun.m_isAlive = false;
			m_health--;
		}
	}


	// ゲームオーバー処理
	for (int number = 0; number != 49; ++number)
	{
		if (!ms_enemyArray[number].m_isAlive) continue;


		if (ms_enemyArray[number].m_areaY >= 900)
		{
			me_now = EScene::gameOver;
		}
	}
	if (m_enemyBosAreaY >= 900 && m_isEnemyBosAlive)
	{
		me_now = EScene::gameOver;
	}


	// ゲームクリア処理
	for (int number = 0; number != 49; ++number)
	{
		if (ms_enemyArray[number].m_isAlive) break;

		if (number == 48)
		{
			if (!m_isEnemyBosAlive)
			{
				me_now = EScene::gameClear;
			}
		}
	}
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameClearProcess()
{
	if (KeyData::Get(KEY_INPUT_Z) == 1)
	{
		me_now = EScene::gameOver;
	}
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameOverProcess()
{
	if (KeyData::Get(KEY_INPUT_Z) == 1)
	{
		if (m_isGameOverUI)
		{
			me_now = EScene::title;
		}
		else
		{
			GameInit();
			me_now = EScene::game;
		}
	}


	if (KeyData::Get(KEY_INPUT_UP) == 1)
	{
		m_isGameOverUI = false;
	}
	if (KeyData::Get(KEY_INPUT_DOWN) == 1)
	{
		m_isGameOverUI = true;
	}
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameInit()
{
	m_preScore = m_score;

	m_preHealth = m_health;

	m_health = 3;

	m_playerX = 480;

	m_score = 0;

	ZeroMemory(ms_enemyArray, sizeof(ms_enemyArray));
	int number = 0;
	for (int i = 0; i != 7; ++i)
	{
		for (int j = 0; j != 7; ++j)
		{
			std::random_device rnd;     // 非決定的な乱数生成器を生成
			std::mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
			std::uniform_int_distribution<> rand05(0, 5);        // [0, 5] 範囲の一様乱数
			ms_enemyArray[number].m_type = (rand05(mt) % 2) == 0 ? EType::circle : EType::box;
			ms_enemyArray[number].m_areaX = 330 + (j * 50);
			ms_enemyArray[number].m_areaY = 250 + (i * 40);
			ms_enemyArray[number].m_isAlive = true;
			ms_enemyArray[number].ms_gun = { false,  330 + (j * 50), 250 + (i * 40) };
			std::uniform_int_distribution<> rand0EnemyMoveSide(1, m_enemyMoveSide);        // [0, m_enemyMoveSide] 範囲の一様乱数
			ms_enemyArray[number].m_gunShotTime = rand0EnemyMoveSide(mt);
			number++;
		}
	}

	m_isEnemyBosAlive = true;

	m_enemyMoveTime = 0;

	m_isEnemyMoveRight = false;

	m_isEnemyMoveDown = false;

	m_enemyBosAreaY = 180;

	ZeroMemory(ms_playerGun, sizeof(ms_playerGun));
	for (int i = 0; i != 7; ++i)
	{
		ms_playerGun[i].m_areaX = m_playerX;
		ms_playerGun[i].m_areaY = m_playerY;
		ms_playerGun[i].m_isAlive = false;
	}
}



/// ------------------------------------------------------------------------------------------------------------
Game::Game()
{
	me_now = EScene::title;

	m_isTitleUI = false;

	m_isGameOverUI = false;

	m_isEnd = false;



	m_health = 0;

	m_score = 0;

	GameInit();
}



/// ------------------------------------------------------------------------------------------------------------
Game::~Game()
{
	ZeroMemory(ms_enemyArray, sizeof(ms_enemyArray));
	ZeroMemory(ms_playerGun, sizeof(ms_playerGun));
}



/// ------------------------------------------------------------------------------------------------------------
void Game::UpDate()
{
	Draw();

	Process();
}
