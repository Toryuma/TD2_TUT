#pragma once

#include "Model.h"
#include "WorldTransform.h"

class RailCamera {
public:
	// ������
	void Initialize();

	// �X�V
	void Update();

private:
	// ���[���h�ϊ��f�[�^
	WorldTransform worldtransform_;
	// �r���[�v���W�F�N�V����
	ViewProjection viewprojection_;
};
