#include "Enemy.h"
#include "GameScene.h"
#include <cassert>

Enemy::~Enemy() {

}

void Enemy::Initialize(Model* model, Vector3& position, const Vector3& velocity) { 
	assert(model);
	model_ = model;
	texturehandle_ = TextureManager::Load("tex1.png");

	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	// 引数で受け取った初期座標をセット
	worldTransform_.translation_ = position;
	// 引数で受け取った速度をメンバ変数に代入
	velocity_ = velocity;
	// 接近フェーズ初期化
}

void Enemy::Update(){

	
}

void Enemy::OnCollision() { isDead_ = true; }


