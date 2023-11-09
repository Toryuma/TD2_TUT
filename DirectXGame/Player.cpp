#include "Player.h"
#include "GameScene.h"
#include <cassert>

Player::~Player() {

}

void Player::Initialize(Model* model, Vector3& position, const Vector3& velocity) { 
	assert(model);
	model_ = model;
	texturehandle_ = TextureManager::Load("tex1.png");

	Vector3 pos;
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;

	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	// 引数で受け取った初期座標をセット
	worldTransform_.translation_ = position;
	// 引数で受け取った速度をメンバ変数に代入
	velocity_ = velocity;
	// 接近フェーズ初期化
}

void Player::Update(){
	Vector3 pos;
	if (pos.x<=pos.y) {

	}
}

void Player::OnCollision() { 
	isDead_ = true;

}


