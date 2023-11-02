#include "Enemy.h"
#include "GameScene.h"

Enemy::~Enemy() {

}

void Enemy::Initialize(Model* model, Vector3& position, const Vector3& velocity) { 
	assert(model);
	model_ = model;
	texturehandle_ = TextureManager::Load("tex1.png");

	// ���[���h�g�����X�t�H�[���̏�����
	worldTransform_.Initialize();
	// �����Ŏ󂯎�����������W���Z�b�g
	worldTransform_.translation_ = position;
	// �����Ŏ󂯎�������x�������o�ϐ��ɑ��
	velocity_ = velocity;
	// �ڋ߃t�F�[�Y������
}

void Enemy::Update(){

	
}

void Enemy::OnCollision() { isDead_ = true; }


