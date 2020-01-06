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

	DrawBox(960 / 2 - 10, 1080 / 2 - 2, 960 / 2 + 60, 1080 / 2 + 20, GetColor(255, 255, 255), false);
	DrawFormatString(960 / 2, 1080 / 2, GetColor(255, 255, 255), "‚©‚¢‚µ");

	DrawBox(960 / 2 - 10, 1080 / 2 + 64 - 2, 960 / 2 + 60, 1080 / 2 + 64 + 20, GetColor(255, 255, 255), false);
	DrawFormatString(960 / 2, 1080 / 2 + 64, GetColor(255, 255, 255), "‚â‚ß‚é");
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

	DrawBox(960 / 2 - 10, 1080 / 2 - 2, 960 / 2 + 120, 1080 / 2 + 20, GetColor(255, 255, 255), false);
	DrawFormatString(960 / 2, 1080 / 2, GetColor(255, 255, 255), "‚½‚¢‚Æ‚é‚à‚Ç‚é");
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameOverDraw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameOver");

	DrawBox(960 / 2 - 10, 1080 / 2 - 2, 960 / 2 + 100, 1080 / 2 + 20, GetColor(255, 255, 255), false);
	DrawFormatString(960 / 2, 1080 / 2, GetColor(255, 255, 255), "‚â‚è‚È‚¨‚·");


	DrawBox(960 / 2 - 10, 1080 / 2 + 64 - 2, 960 / 2 + 120, 1080 / 2 + 64 + 20, GetColor(255, 255, 255), false);
	DrawFormatString(960 / 2, 1080 / 2 + 64, GetColor(255, 255, 255), "‚½‚¢‚Æ‚é‚à‚Ç‚é");
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
#ifdef _DEBUG
	if (KeyData::Get(KEY_INPUT_Z) == 1)
	{
		me_now = EScene::game;
	}
#endif
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
#ifdef _DEBUG
	if (KeyData::Get(KEY_INPUT_Z) == 1)
	{
		me_now = EScene::gameOver;
	}
#endif
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameOverProcess()
{
#ifdef _DEBUG
	if (KeyData::Get(KEY_INPUT_Z) == 1)
	{
		me_now = EScene::title;
	}
#endif
}



/// ------------------------------------------------------------------------------------------------------------
Game::Game()
{
	me_now = EScene::title;
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
