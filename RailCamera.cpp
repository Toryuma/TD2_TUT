#include "RailCamera.h"

void RailCamera::Initialize()
{
	// ���[���h�g�����X�t�H�[���̏������A�ݒ�
	worldtransform_.Initialize();
	worldtransform_.translation_.z = -10;

	// �r���[�v���W�F�N�V�����̏�����
	viewprojection_.Initialize();
}

void RailCamera::Update()
{
	worldtransform_.translation_.z += 0.05f;
	worldtransform_.UpdateMatrix();
}
