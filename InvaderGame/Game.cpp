#include "Game.hpp"



/// ------------------------------------------------------------------------------------------------------------
void Game::TypeDraw(const EType t_type, const int t_centerAreaX, const int t_centerAreaY, const int t_size)
{
	switch (t_type)
	{
	case EType::bigCircle:
		DrawCircle(t_centerAreaX, t_centerAreaY, t_size * 3, GetColor(255, 255, 255));
		break;

		
	case EType::box:
		DrawBox(t_centerAreaX - t_size, t_centerAreaY - t_size, t_centerAreaX + t_size, t_centerAreaY + t_size, GetColor(255, 255, 255), true);
		break;


	case EType::circle:
		DrawCircle(t_centerAreaX, t_centerAreaY, t_size, GetColor(255, 255, 255));
		break;


	case EType::triangle:
		DrawTriangle(t_centerAreaX - t_size, t_centerAreaY + t_size, t_centerAreaX, t_centerAreaY - t_size, t_centerAreaX + t_size, t_centerAreaY + t_size, GetColor(255, 255, 255), true);
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
		DrawBox(960 / 2 - 10, 960 / 2 - 2, 960 / 2 + 60, 960 / 2 + 20, GetColor(255, 255, 255), false);
	}
	else
	{
		DrawBox(960 / 2 - 10, 960 / 2 - 2, 960 / 2 + 60, 960 / 2 + 20, GetColor(255, 0, 0), false);
	}
	DrawFormatString(960 / 2, 960 / 2, GetColor(255, 255, 255), "かいし");

	if (m_isTitleUI)
	{
		DrawBox(960 / 2 - 10, 960 / 2 + 64 - 2, 960 / 2 + 60, 960 / 2 + 64 + 20, GetColor(255, 0, 0), false);
	}
	else
	{
		DrawBox(960 / 2 - 10, 960 / 2 + 64 - 2, 960 / 2 + 60, 960 / 2 + 64 + 20, GetColor(255, 255, 255), false);
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
	DrawBox(30, 30, 930, 930, GetColor(255, 255, 255), false);


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


	// ゲーム枠
	DrawBox(180, 60, 960 - 180, 960 - 60, GetColor(255, 255, 255), false);


	// スコア
	DrawFormatString(40, 80, GetColor(255, 255, 255), "すこあ\n%05d", m_score);


	// 敵大将
	TypeDraw(EType::bigCircle, 480, 180);


	// 雑魚
	int number = 0;
	for (int i = 0; i != 7; ++i)
	{
		for (int j = 0; j != 7; ++j)
		{
			if (ms_enemyArray[number].m_isAlive)
			{
				TypeDraw(ms_enemyArray[number].m_type, ms_enemyArray[number].m_areaX, ms_enemyArray[number].m_areaY);
			}
			number++;
		}
	}


	// プレイヤー
	TypeDraw(EType::triangle, m_playerX, m_playerY);
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameClearDraw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameClear");

	DrawBox(960 / 2 - 10, 960 / 2 - 2, 960 / 2 + 120, 960 / 2 + 20, GetColor(255, 0, 0), false);
	DrawFormatString(960 / 2, 960 / 2, GetColor(255, 255, 255), "たいとるもどる");

	DrawFormatString(960 - 110, 960 - 64, GetColor(255, 255, 255), "Zきーをおせ");
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameOverDraw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameOver");

	if (m_isGameOverUI)
	{
		DrawBox(960 / 2 - 10, 960 / 2 - 2, 960 / 2 + 100, 960 / 2 + 20, GetColor(255, 255, 255), false);
	}
	else
	{
		DrawBox(960 / 2 - 10, 960 / 2 - 2, 960 / 2 + 100, 960 / 2 + 20, GetColor(255, 0, 0), false);
	}
	DrawFormatString(960 / 2, 960 / 2, GetColor(255, 255, 255), "やりなおす");

	if (m_isGameOverUI)
	{
		DrawBox(960 / 2 - 10, 960 / 2 + 64 - 2, 960 / 2 + 120, 960 / 2 + 64 + 20, GetColor(255, 0, 0), false);
	}
	else
	{
		DrawBox(960 / 2 - 10, 960 / 2 + 64 - 2, 960 / 2 + 120, 960 / 2 + 64 + 20, GetColor(255, 255, 255), false);
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
#ifdef _DEBUG
	if (KeyData::Get(KEY_INPUT_Z) == 1)
	{
		me_now = EScene::gameClear;
	}
#endif


	// プレイヤー左右
	if ((KeyData::Get(KEY_INPUT_RIGHT) % 15) == 0 && KeyData::Get(KEY_INPUT_RIGHT) != 0)
	{
		if (m_playerX < 960 - 230)
		{
			m_playerX += 10;
		}
	}
	if ((KeyData::Get(KEY_INPUT_LEFT) % 15) == 0 && KeyData::Get(KEY_INPUT_LEFT) != 0)
	{
		if (m_playerX > 230)
		{
			m_playerX -= 10;
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
Game::Game()
{
	me_now = EScene::title;

	m_isTitleUI = false;

	m_isGameOverUI = false;

	m_isEnd = false;

	m_health = 3;

	m_playerX = 480;

	m_score = 0;

	int number = 0;
	for (int i = 0; i != 7; ++i)
	{
		for (int j = 0; j != 7; ++j)
		{
			std::random_device rnd;     // 非決定的な乱数生成器を生成
			std::mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
			std::uniform_int_distribution<> rand05(0, 5);        // [0, 5] 範囲の一様乱数
			ms_enemyArray[number++] = { (rand05(mt) % 2) == 0 ? EType::circle : EType::box, 330 + (j * 50), 250 + (i * 40) , true };
		}
	}
}



/// ------------------------------------------------------------------------------------------------------------
Game::~Game()
{
}



/// ------------------------------------------------------------------------------------------------------------
void Game::UpDate()
{
	Draw();

	Process();
}
