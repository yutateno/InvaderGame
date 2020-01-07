#include "Game.hpp"



/// ------------------------------------------------------------------------------------------------------------
bool Game::GunCheckBoxColl(const int t_centerX, const int t_centerY, const SGun t_gun)
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
bool Game::GunCheckCircleColl(const int t_centerX, const int t_centerY, const SGun t_gun, const int t_circleR)
{
	const float centerX = static_cast<float>(t_centerX);
	const float centerY = static_cast<float>(t_centerY);
	const float centerR = static_cast<float>(t_circleR);

	// DrawBox(m_gunAreaX - 2, m_gunAreaY, m_gunAreaX + 2, m_gunAreaY + 5, GetColor(255, 255, 255), true);
	const float gunLeft = static_cast<float>(t_gun.m_areaX - 2);
	const float gunTop = static_cast<float>(t_gun.m_areaY);
	const float gunRight = static_cast<float>(t_gun.m_areaX + 2);
	const float gunBottom = static_cast<float>(t_gun.m_areaY + 5);

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
		if(!m_isSmallEnemyEnd)
		{
			DrawCircleAA(static_cast<float>(t_centerAreaX), static_cast<float>(t_centerAreaY)
				, static_cast<float>(t_size), 32, GetColor(175, 255, 255), true);
		}
		else
		{
			DrawCircleAA(static_cast<float>(t_centerAreaX), static_cast<float>(t_centerAreaY)
				, static_cast<float>(t_size), 32, GetColor(175, 175, 175), true);
		}
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

	DrawFormatString(960 - 160, 960 - 300, GetColor(255, 255, 255), "���傤���ł��ǂ�\n\nZ���[������");
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameDraw()
{
	if (me_now == EScene::game)
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Game");
		DrawFormatString(960 - 160, 960 - 300, GetColor(255, 255, 255), "Z���[ ��\n���� �ł� ��\n\n���䂤 �₶�邵\n�L�[ ��\n������ ��");
	}

	if (m_startTimer > 10)
	{
		// �S�̘g
		DrawBoxAA(30, 30, 930, 930, GetColor(255, 255, 255), false);
	}


	if (m_startTimer > 20)
	{
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
	}


	if (m_startTimer > 30)
	{
		// �X�R�A
		DrawFormatString(40, 80, GetColor(255, 255, 255), "������\n%05d", m_score);


		// �O��X�R�A
		DrawFormatString(960 - 160, 80, GetColor(255, 255, 255), "�O��X�R�A\n%05d\n�O��w���X\n%05d", m_preScore, m_preHealth);
	}


	if (m_startTimer > 40)
	{
		// �Q�[���g
		DrawBoxAA(180, 60, 960 - 180, 960 - 60, GetColor(255, 255, 255), false);
	}


	if (m_startTimer > 60)
	{
		// �G�叫
		if (m_enemyBossHealth > 0)
		{
			TypeDraw(EType::bigCircle, 480, m_enemyBossAreaY, m_enemyBossCircle + m_enemyBossNoDamageEffect);
		}
	}


	if (m_startTimer > 70 && m_startTimer < 119)
	{
		for (int number = 0; number <= m_startTimer - 70; ++number)
		{
			if (ms_enemyArray[number].m_isAlive)
			{
				TypeDraw(ms_enemyArray[number].m_type, ms_enemyArray[number].m_areaX, ms_enemyArray[number].m_areaY);
			}
		}
	}
	else if (m_startTimer >= 119)
	{
		// �G��
		if (!m_isSmallEnemyEnd)
		{
			for (int number = 0; number != 49; ++number)
			{
				if (ms_enemyArray[number].m_isAlive)
				{
					TypeDraw(ms_enemyArray[number].m_type, ms_enemyArray[number].m_areaX, ms_enemyArray[number].m_areaY);
				}
			}
		}
	}


	if (m_startTimer > 50)
	{
		// �v���C���[
		TypeDraw(EType::triangle, m_playerX, m_playerY);
	}


	// �G�̒e
	if (!m_isSmallEnemyEnd)
	{
		for (int number = 0; number != 49; ++number)
		{
			if (ms_enemyArray[number].ms_gun.m_isAlive)
			{
				DrawBox(ms_enemyArray[number].ms_gun.m_areaX - 2, ms_enemyArray[number].ms_gun.m_areaY
					, ms_enemyArray[number].ms_gun.m_areaX + 2, ms_enemyArray[number].ms_gun.m_areaY + 5, GetColor(255, 255, 255), true);
			}
		}
	}


	// �v���C���[�̒e
	for (int i = 0; i != 7; ++i)
	{
		if (ms_playerGun[i].m_isAlive)
		{
			DrawBox(ms_playerGun[i].m_areaX - 2, ms_playerGun[i].m_areaY, ms_playerGun[i].m_areaX + 2, ms_playerGun[i].m_areaY + 5, GetColor(255, 200, 200), true);
		}
	}


	// �J�E���g�_�E��
	if (m_startTimer > 120 && m_startTimer < 130)
	{
		DrawString(480, 800, "333", GetColor(255, 255, 255));
	}
	else if (m_startTimer > 130 && m_startTimer < 140)
	{
		DrawString(480, 800, "22", GetColor(255, 255, 255));
	}
	else if (m_startTimer > 140 && m_startTimer < 150)
	{
		DrawString(480, 800, "1", GetColor(255, 255, 255));
	}
}



/// ------------------------------------------------------------------------------------------------------------
void Game::GameClearDraw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameClear");

	DrawBoxAA(960 / 2 - 10, 960 / 2 - 2, 960 / 2 + 120, 960 / 2 + 20, GetColor(255, 0, 0), false);
	DrawFormatString(960 / 2, 960 / 2, GetColor(255, 255, 255), "�����Ƃ���ǂ�");

	DrawFormatString(960 - 160, 960 - 300, GetColor(255, 255, 255), "���傤���ł��ǂ�\n\nZ���[������");
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

	DrawFormatString(960 - 160, 960 - 300, GetColor(255, 255, 255), "���傤���ł��ǂ�\n\nZ���[������");
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
	if (m_startTimer < 150)
	{
		m_startTimer++;
	}
	else
	{
		// �v���C���[���E
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


		// �v���C���[�̒e�̐���
		if (KeyData::Get(KEY_INPUT_Z) == 1)
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


		// �v���C���[�̒e�̓���
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


				if (m_enemyBossHealth > 0)
				{
					if (GunCheckCircleColl(480, m_enemyBossAreaY, ms_playerGun[k], m_enemyBossCircle))
					{
						m_enemyBossNoDamageEffect = 5;
						if (m_isSmallEnemyEnd)
						{
							m_score += 30;
							m_enemyBossHealth--;
						}
						ms_playerGun[k].m_isAlive = false;
					}
				}


				if (!m_isSmallEnemyEnd)
				{
					for (int number = 0; number != 49; ++number)
					{
						if (!ms_enemyArray[number].m_isAlive) continue;


						if (ms_enemyArray[number].m_type == EType::box)
						{
							if (GunCheckBoxColl(ms_enemyArray[number].m_areaX, ms_enemyArray[number].m_areaY, ms_playerGun[k]))
							{
								m_score += 5;
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
					}
				}
			}
		}


		// �G�叫�̑傫��
		if (m_enemyBossCircle != m_enemyBossHealth * 3 && m_enemyBossHealth > 0)
		{
			m_enemyBossCircle = m_enemyBossHealth * 3;
		}
		if (m_enemyBossNoDamageEffect > 0) m_enemyBossNoDamageEffect--;


		// �G�̓����J�E���g
		m_enemyMoveTime++;


		// �G���G�������������ׂ�
		if (!m_isSmallEnemyEnd)
		{
			for (int number = 0; number != 49; ++number)
			{
				if (ms_enemyArray[number].m_isAlive)
				{
					m_isSmallEnemyEnd = false;
					break;
				}
				else
				{
					if(!m_isSmallEnemyEnd) m_isSmallEnemyEnd = true;
				}
			}
		}


		// �G�����E�ɓ�����
		if (m_enemyMoveTime % m_enemyMoveSide == 0 && m_enemyMoveTime > 0)
		{
			if (!m_isSmallEnemyEnd)
			{
				for (int number = 1; number != 48; ++number)
				{
					if (!ms_enemyArray[number].m_isAlive) continue;
					if (m_isEnemyMoveRight)
					{
						ms_enemyArray[number].m_areaX += 20;
					}
					else
					{
						ms_enemyArray[number].m_areaX -= 20;
					}
				}
			}
			if (m_isEnemyMoveRight)
			{
				ms_enemyArray[0].m_areaX += 20;
				ms_enemyArray[48].m_areaX += 20;
			}
			else
			{
				ms_enemyArray[0].m_areaX -= 20;
				ms_enemyArray[48].m_areaX -= 20;
			}


			// ���[�̂��̂�������ɍs������
			if (ms_enemyArray[0].m_areaX <= 230)
			{
				m_isEnemyMoveRight = true;
				m_isEnemyMoveDown = true;
				m_enemyMoveTime = -(m_enemyMoveSide * 2);
			}


			// �E�[�̂��̂��E����ɍs������
			if (ms_enemyArray[48].m_areaX >= 960 - 230)
			{
				m_isEnemyMoveRight = false;
				m_isEnemyMoveDown = true;
				m_enemyMoveTime = -(m_enemyMoveSide * 2);
			}
		}


		// �G������������
		if (m_isEnemyMoveDown && m_enemyMoveTime == -m_enemyMoveSide)
		{
			if (!m_isSmallEnemyEnd)
			{
				for (int number = 0; number != 49; ++number)
				{
					ms_enemyArray[number].m_areaY += 25;
				}
			}


			m_enemyBossAreaY += 25;
			if (m_isEnemyMoveDown) m_isEnemyMoveDown = false;
		}


		// �G�̒e
		if (!m_isSmallEnemyEnd)
		{
			for (int number = 0; number != 49; ++number)
			{
				// �G���e�������Ă�����
				if (ms_enemyArray[number].ms_gun.m_isAlive)
				{
					ms_enemyArray[number].ms_gun.m_areaY += 5;
					if (ms_enemyArray[number].ms_gun.m_areaY > 960 - 60 - 5)
					{
						ms_enemyArray[number].ms_gun.m_isAlive = false;
						continue;
					}
				}


				// �G������ł��Ȃ�������
				if (ms_enemyArray[number].m_isAlive)
				{
					if (!ms_enemyArray[number].ms_gun.m_isAlive && m_enemyMoveTime % ms_enemyArray[number].m_gunShotTime == 0 && m_enemyMoveTime > 0)
					{
						ms_enemyArray[number].ms_gun.m_isAlive = true;
						ms_enemyArray[number].ms_gun.m_areaX = ms_enemyArray[number].m_areaX;
						ms_enemyArray[number].ms_gun.m_areaY = ms_enemyArray[number].m_areaY;
					}
				}


				// �G�ɓ����������ǂ���
				if (GunCheckCircleColl(m_playerX, m_playerY, ms_enemyArray[number].ms_gun))
				{
					ms_enemyArray[number].ms_gun.m_isAlive = false;
					m_health--;
				}
			}
		}


		// �Q�[���I�[�o�[����
		if (!m_isSmallEnemyEnd)
		{
			for (int number = 0; number != 49; ++number)
			{
				if (!ms_enemyArray[number].m_isAlive) continue;


				if (ms_enemyArray[number].m_areaY >= 900)
				{
					me_now = EScene::gameOver;
				}
			}
		}
		if (m_enemyBossAreaY >= 900 && m_enemyBossHealth > 0)
		{
			me_now = EScene::gameOver;
		}


		// �Q�[���N���A����
		if (m_isSmallEnemyEnd)
		{
			if (m_enemyBossHealth == 0)
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
		me_now = EScene::title;
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

	m_enemyBossHealth = 10;

	m_enemyBossCircle = m_enemyBossHealth * 3;

	ZeroMemory(ms_enemyArray, sizeof(ms_enemyArray));
	int number = 0;
	for (int i = 0; i != 7; ++i)
	{
		for (int j = 0; j != 7; ++j)
		{
			std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
			std::mt19937 mt(rnd());     //  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
			std::uniform_int_distribution<> rand05(0, 5);        // [0, 5] �͈͂̈�l����
			ms_enemyArray[number].m_type = (rand05(mt) % 2) == 0 ? EType::circle : EType::box;
			ms_enemyArray[number].m_areaX = 330 + (j * 50);
			ms_enemyArray[number].m_areaY = 250 + (i * 40);
			ms_enemyArray[number].m_isAlive = true;
			ms_enemyArray[number].ms_gun = { false,  330 + (j * 50), 250 + (i * 40) };
			std::uniform_int_distribution<> rand0EnemyMoveSide(1, m_enemyMoveSide);        // [0, m_enemyMoveSide] �͈͂̈�l����
			ms_enemyArray[number].m_gunShotTime = rand0EnemyMoveSide(mt);
			number++;
		}
	}

	m_enemyMoveTime = 0;

	m_isEnemyMoveRight = false;

	m_isEnemyMoveDown = false;

	m_enemyBossAreaY = 180;

	ZeroMemory(ms_playerGun, sizeof(ms_playerGun));
	for (int i = 0; i != 7; ++i)
	{
		ms_playerGun[i].m_areaX = m_playerX;
		ms_playerGun[i].m_areaY = m_playerY;
		ms_playerGun[i].m_isAlive = false;
	}

	m_startTimer = 0;

	m_isSmallEnemyEnd = false;

	m_enemyBossNoDamageEffect = 0;
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
