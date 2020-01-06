#include "Game.hpp"



/// ------------------------------------------------------------------------------------------------------------
void Game::Draw()
{
	GameDraw();


	switch (me_now)
	{
	case EScene::title:
		TitleDraw();
		break;


	case EScene::game:
		break;


	case EScene::gameClear:
		GameClearDraw();
		break;


	case EScene::gameOver:
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

	if (m_titleUI)
	{
		DrawBox(960 / 2 - 10, 1080 / 2 - 2, 960 / 2 + 60, 1080 / 2 + 20, GetColor(255, 255, 255), false);
	}
	else
	{
		DrawBox(960 / 2 - 10, 1080 / 2 - 2, 960 / 2 + 60, 1080 / 2 + 20, GetColor(255, 0, 0), false);
	}
	DrawFormatString(960 / 2, 1080 / 2, GetColor(255, 255, 255), "Ç©Ç¢Çµ");

	if (m_titleUI)
	{
		DrawBox(960 / 2 - 10, 1080 / 2 + 64 - 2, 960 / 2 + 60, 1080 / 2 + 64 + 20, GetColor(255, 0, 0), false);
	}
	else
	{
		DrawBox(960 / 2 - 10, 1080 / 2 + 64 - 2, 960 / 2 + 60, 1080 / 2 + 64 + 20, GetColor(255, 255, 255), false);
	}
	DrawFormatString(960 / 2, 1080 / 2 + 64, GetColor(255, 255, 255), "Ç‚ÇﬂÇÈ");

	DrawFormatString(960 - 110, 1080 - 64, GetColor(255, 255, 255), "ZÇ´Å[ÇÇ®Çπ");
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameDraw()
{
	if (me_now == EScene::game)
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Game");
	}
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameClearDraw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameClear");

	DrawBox(960 / 2 - 10, 1080 / 2 - 2, 960 / 2 + 120, 1080 / 2 + 20, GetColor(255, 0, 0), false);
	DrawFormatString(960 / 2, 1080 / 2, GetColor(255, 255, 255), "ÇΩÇ¢Ç∆ÇÈÇ‡Ç«ÇÈ");

	DrawFormatString(960 - 110, 1080 - 64, GetColor(255, 255, 255), "ZÇ´Å[ÇÇ®Çπ");
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameOverDraw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameOver");

	if (m_gameOverUI)
	{
		DrawBox(960 / 2 - 10, 1080 / 2 - 2, 960 / 2 + 100, 1080 / 2 + 20, GetColor(255, 255, 255), false);
	}
	else
	{
		DrawBox(960 / 2 - 10, 1080 / 2 - 2, 960 / 2 + 100, 1080 / 2 + 20, GetColor(255, 0, 0), false);
	}
	DrawFormatString(960 / 2, 1080 / 2, GetColor(255, 255, 255), "Ç‚ÇËÇ»Ç®Ç∑");

	if (m_gameOverUI)
	{
		DrawBox(960 / 2 - 10, 1080 / 2 + 64 - 2, 960 / 2 + 120, 1080 / 2 + 64 + 20, GetColor(255, 0, 0), false);
	}
	else
	{
		DrawBox(960 / 2 - 10, 1080 / 2 + 64 - 2, 960 / 2 + 120, 1080 / 2 + 64 + 20, GetColor(255, 255, 255), false);
	}
	DrawFormatString(960 / 2, 1080 / 2 + 64, GetColor(255, 255, 255), "ÇΩÇ¢Ç∆ÇÈÇ‡Ç«ÇÈ");

	DrawFormatString(960 - 110, 1080 - 64, GetColor(255, 255, 255), "ZÇ´Å[ÇÇ®Çπ");
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
		if(m_titleUI)
		{
			m_end = true;
		}
		else
		{
			me_now = EScene::game;
		}
	}


	if (KeyData::Get(KEY_INPUT_UP) == 1)
	{
		m_titleUI = false;
	}
	if (KeyData::Get(KEY_INPUT_DOWN) == 1)
	{
		m_titleUI = true;
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
		if (m_gameOverUI)
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
		m_gameOverUI = false;
	}
	if (KeyData::Get(KEY_INPUT_DOWN) == 1)
	{
		m_gameOverUI = true;
	}
}



/// ------------------------------------------------------------------------------------------------------------
Game::Game()
{
	me_now = EScene::title;

	m_titleUI = false;

	m_gameOverUI = false;

	m_end = false;
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
