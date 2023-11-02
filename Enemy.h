#pragma once
#include "Input.h"
#include "Model.h"
#include "WorldTransform.h"
#include <list>

class Enemy {
public:
	//�f���[�g
	~Enemy();
	//������
	void Initialize(Model* model, Vector3& position, const Vector3& velocity);
	//�X�V
	void Update();
	//�`��
	void Draw(ViewProjection& viewProjection);
	//�����蔻��
	void OnCollision();
	//���S�t���O
	bool IsDead() const { return isDead_; }

private:

	WorldTransform worldTransform_;
	Model* model_ = nullptr;
	uint32_t texturehandle_ = 0u;
	// ���x
	Vector3 velocity_;

	bool isDead_ = false;
};
