#include "Game.hpp"



/// ------------------------------------------------------------------------------------------------------------
bool Game::GunCheckCircleColl(const int t_centerX, const int t_centerY)
{
	const float left = static_cast<float>(t_centerX - 10);
	const float top = static_cast<float>(t_centerY - 10);
	const float right = static_cast<float>(t_centerX + 10);
	const float bottom = static_cast<float>(t_centerY + 10);

	// DrawBox(m_gunAreaX - 2, m_gunAreaY, m_gunAreaX + 2, m_gunAreaY + 5, GetColor(255, 255, 255), true);
	const float gunLeft = static_cast<float>(m_gunAreaX - 2);
	const float gunTop = static_cast<float>(m_gunAreaY);
	const float gunRight = static_cast<float>(m_gunAreaX + 2);
	const float gunBottom = static_cast<float>(m_gunAreaY + 5);

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
bool Game::GunCheckBoxColl(const int t_centerX, const int t_centerY)
{
	const float centerX = static_cast<float>(t_centerX);
	const float centerY = static_cast<float>(t_centerY);
	const float centerR = 10.0f;

	// DrawBox(m_gunAreaX - 2, m_gunAreaY, m_gunAreaX + 2, m_gunAreaY + 5, GetColor(255, 255, 255), true);
	const float gunLeft = static_cast<float>(m_gunAreaX - 2);
	const float gunTop = static_cast<float>(m_gunAreaY);
	const float gunRight = static_cast<float>(m_gunAreaX + 2);
	const float gunBottom = static_cast<float>(m_gunAreaY + 5);

	bool nResult = false;

	// �l�p�`�̎l�ӂɑ΂��ĉ~�̔��a�������������Ƃ��~���d�Ȃ��Ă�����
	if ((centerX > gunLeft - centerR) && (centerX < gunRight + centerR) &&
		(centerY > gunTop - centerR) && (centerY < gunBottom + centerR))
	{
		nResult = true;
		float fl = centerR * centerR;


		// ��
		if (centerX < gunLeft)
		{
			// ����
			if ((centerY < gunTop))
			{
				float dx = centerX - gunLeft;
				float dy = centerY - gunTop;

				float distanceSqrf = (dx * dx) + (dy * dy);

				// �d�Ȃ��Ă��Ȃ�
				if (distanceSqrf >= fl)
				{
					nResult = false;
				}
			}
			else
			{
				// ����
				if ((centerY > gunBottom))
				{
					float dx = centerX - gunLeft;
					float dy = centerY - gunBottom;

					float distanceSqrf = (dx * dx) + (dy * dy);

					// �d�Ȃ��Ă��Ȃ�
					if (distanceSqrf >= fl)
					{
						nResult = false;
					}
				}
			}
		}
		else
		{
			// �E
			if (centerX > gunRight)
			{
				// �E��
				if ((centerY < gunTop))
				{
					float dx = centerX - gunRight;
					float dy = centerY - gunTop;

					float distanceSqrf = (dx * dx) + (dy * dy);

					// �d�Ȃ��Ă��Ȃ�
					if (distanceSqrf >= fl)
					{
						nResult = false;
					}
				}
				else
				{
					// �E��
					if ((centerY > gunBottom))
					{
						float dx = centerX - gunRight;
						float dy = centerY - gunBottom;

						float distanceSqrf = (dx * dx) + (dy * dy);

						// �d�Ȃ��Ă��Ȃ�
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
	DrawFormatString(960 / 2, 960 / 2, GetColor(255, 255, 255), "������");

	if (m_isTitleUI)
	{
		DrawBoxAA(960 / 2 - 10, 960 / 2 + 64 - 2, 960 / 2 + 60, 960 / 2 + 64 + 20, GetColor(255, 0, 0), false);
	}
	else
	{
		DrawBoxAA(960 / 2 - 10, 960 / 2 + 64 - 2, 960 / 2 + 60, 960 / 2 + 64 + 20, GetColor(255, 255, 255), false);
	}
	DrawFormatString(960 / 2, 960 / 2 + 64, GetColor(255, 255, 255), "��߂�");

	DrawFormatString(960 - 110, 960 - 64, GetColor(255, 255, 255), "Z���[������");
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameDraw()
{
	if (me_now == EScene::game)
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Game");
	}


	// �S�̘g
	DrawBoxAA(30, 30, 930, 930, GetColor(255, 255, 255), false);


	// �c��
	DrawFormatString(35, 930 - 60, GetColor(255, 255, 255), "���񂫁F%d", m_health - 1);
	if (m_health == 3)
	{
		TypeDraw(EType::triangle, 50, 930 - 30, 8);
		TypeDraw(EType::triangle, 70, 930 - 30, 8);
	}
	else if (m_health == 2)
	{
		TypeDraw(EType::triangle, 50, 930 - 30);
	}


	// �Q�[���g
	DrawBoxAA(180, 60, 960 - 180, 960 - 60, GetColor(255, 255, 255), false);


	// �X�R�A
	DrawFormatString(40, 80, GetColor(255, 255, 255), "������\n%05d", m_score);


	// �G�叫
	TypeDraw(EType::bigCircle, 480, m_enemyBosAreaY);


	// �G��
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


	// �v���C���[
	TypeDraw(EType::triangle, m_playerX, m_playerY);


	// �e
	if (m_gunAlive)
	{
		DrawBox(m_gunAreaX - 2, m_gunAreaY, m_gunAreaX + 2, m_gunAreaY + 5, GetColor(255, 255, 255), true);
	}
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameClearDraw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameClear");

	DrawBoxAA(960 / 2 - 10, 960 / 2 - 2, 960 / 2 + 120, 960 / 2 + 20, GetColor(255, 0, 0), false);
	DrawFormatString(960 / 2, 960 / 2, GetColor(255, 255, 255), "�����Ƃ���ǂ�");

	DrawFormatString(960 - 110, 960 - 64, GetColor(255, 255, 255), "Z���[������");
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
	DrawFormatString(960 / 2, 960 / 2, GetColor(255, 255, 255), "���Ȃ���");

	if (m_isGameOverUI)
	{
		DrawBoxAA(960 / 2 - 10, 960 / 2 + 64 - 2, 960 / 2 + 120, 960 / 2 + 64 + 20, GetColor(255, 0, 0), false);
	}
	else
	{
		DrawBoxAA(960 / 2 - 10, 960 / 2 + 64 - 2, 960 / 2 + 120, 960 / 2 + 64 + 20, GetColor(255, 255, 255), false);
	}
	DrawFormatString(960 / 2, 960 / 2 + 64, GetColor(255, 255, 255), "�����Ƃ���ǂ�");

	DrawFormatString(960 - 110, 960 - 64, GetColor(255, 255, 255), "Z���[������");
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


	// �v���C���[���E
	if ((KeyData::Get(KEY_INPUT_RIGHT) % (m_enemyMoveSide / 2)) == 0 && KeyData::Get(KEY_INPUT_RIGHT) != 0)
	{
		if (m_playerX < 960 - 230)
		{
			m_playerX += 10;
		}
	}
	if ((KeyData::Get(KEY_INPUT_LEFT) % (m_enemyMoveSide / 2)) == 0 && KeyData::Get(KEY_INPUT_LEFT) != 0)
	{
		if (m_playerX > 230)
		{
			m_playerX -= 10;
		}
	}

	
	// �e�̐���
	if (KeyData::Get(KEY_INPUT_G) == 1 && !m_gunAlive)
	{
		m_gunAlive = true;
		m_gunAreaX = m_playerX;
		m_gunAreaY = m_playerY;
	}


	// �e�̓���
	if (m_gunAlive)
	{
		m_gunAreaY -= 5;
		if (m_gunAreaY < 60)
		{
			m_gunAlive = false;
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
					if (GunCheckBoxColl(ms_enemyArray[number].m_areaX, ms_enemyArray[number].m_areaY))
					{
						ms_enemyArray[number].m_isAlive = false;
						m_gunAlive = false;
					}
				}
				else if (ms_enemyArray[number].m_type == EType::circle)
				{
					if (GunCheckCircleColl(ms_enemyArray[number].m_areaX, ms_enemyArray[number].m_areaY))
					{
						ms_enemyArray[number].m_isAlive = false;
						m_gunAlive = false;
					}
				}


				number++;
			}
		}
	}


	// �G�̓����J�E���g
	m_enemyMoveTime++;


	// �G�����E�ɓ�����
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


		// ���[�̂��̂�������ɍs������
		if (ms_enemyArray[0].m_areaX <= 230)
		{
			m_isEnemyMoveRight = true;
			m_isEnemyMoveDown = true;
			m_enemyMoveTime = -(m_enemyMoveSide * 2);
		}


		// �E�[�̂��̂��E����ɍs������
		if (ms_enemyArray[6].m_areaX >= 960 - 230)
		{
			m_isEnemyMoveRight = false;
			m_isEnemyMoveDown = true;
			m_enemyMoveTime = -(m_enemyMoveSide * 2);
		}
	}


	// �G������������
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

	ZeroMemory(ms_enemyArray, sizeof(ms_enemyArray));
	int number = 0;
	for (int i = 0; i != 7; ++i)
	{
		for (int j = 0; j != 7; ++j)
		{
			std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
			std::mt19937 mt(rnd());     //  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
			std::uniform_int_distribution<> rand05(0, 5);        // [0, 5] �͈͂̈�l����
			ms_enemyArray[number++] = { (rand05(mt) % 2) == 0 ? EType::circle : EType::box, 330 + (j * 50), 250 + (i * 40), true };
		}
	}

	m_isEnemyBosAlive = true;

	m_enemyMoveTime = 0;

	m_isEnemyMoveRight = false;

	m_isEnemyMoveDown = false;

	m_enemyBosAreaY = 180;

	m_gunAlive = false;

	m_gunAreaX = m_playerX;

	m_gunAreaY = m_playerY;
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
