#pragma once

#ifndef _INPUTKEY_HPP
#define _INPUTKEY_HPP

#include "DxLib.h"



// �L�[�{�[�h�̓��͏��
class KeyData
{
private:
	static int m_key[256];		// �L�[�̓��͏�Ԋi�[�p�ϐ�
	static char m_tmpKey[256];	// ���݂̃L�[�̓��͏�Ԃ��i�[����


public:
	static void UpDate();			// �L�[���͂̏�ԍX�V


	static const int Get(const int t_keyCode);		// �L�[���͏�Ԏ擾
	static const bool IsCheckEnd();					// �����I��
};

#endif