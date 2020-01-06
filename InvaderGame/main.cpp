#include "DxLib.h"
#include <string>
#include "InputKey.hpp"
#include "Game.hpp"


/// --------------------------------------------------------------------------------------------------
// �E�B���h�E�T�C�Y�����߂�
int winWidth = 0;
int winHeight = 0;
int bitColor = 0;



/// --------------------------------------------------------------------------------------------------
bool Init(const int t_winWidth, const int t_winHeight, const int t_bitColor, std::string t_projectName)
{
	winWidth = t_winWidth;
	winHeight = t_winHeight;
	bitColor = t_bitColor;

#ifdef _DEBUG
	SetOutApplicationLogValidFlag(TRUE);	// ���O�e�L�X�g�o�͂���
#elif NDEBUG
	SetOutApplicationLogValidFlag(FALSE);	// ���O�e�L�X�g�o�͂��Ȃ�
#endif


	SetWindowText(t_projectName.c_str());					// ���C���E�C���h�E�̃E�C���h�E�^�C�g����ύX����
	SetBackgroundColor(0, 0, 0);			// �w�i�F�𔒂ɕύX
	ChangeWindowMode(TRUE);						// �E�B���h�E�Y���[�h�ɂ�����


	SetGraphMode(winWidth, winHeight, bitColor);			// ��ʃT�C�Y�ݒ�
	GetDefaultState(&winWidth, &winHeight, &bitColor);		// �f�t�H���g�E�B���h�E�l�𓾂�
	SetWindowSize(winWidth / 2, winHeight);					// �f�t�H���g�E�B���h�E�T�C�Y�ɍ��킹�ăQ�[���T�C�Y��ύX

	SetUseDirect3DVersion(DX_DIRECT3D_11);		// Direct3D11���g�p����


	SetAlwaysRunFlag(TRUE);				// ����ʂł���ɃA�N�e�B�u�ɕύX

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return false;			// �G���[���N�����璼���ɏI��
	}


	SetAlwaysRunFlag(TRUE);				// ����ʂł���ɃA�N�e�B�u�ɕύX
	SetDrawScreen(DX_SCREEN_BACK);	// �w�i�`��


	return true;
}



/// --------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (Init(960, 1080, 32, "Game") == false) return -1;

	Game m_game = Game();

	// ���C�����[�v
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !KeyData::IsCheckEnd())
	{
		KeyData::UpDate();

		m_game.UpDate();
	}


	// �폜
	m_game.~Game();
	DxLib_End();		// DX���C�u�����̌�n��


	return 0;
}