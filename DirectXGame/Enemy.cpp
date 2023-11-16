#include "Enemy.h"
#include "GameScene.h"
#include <cassert>

//void Enemy::Initialize(Model* model) { 
//
//	assert(model);
//	
//	model_ = model; 
//
//	// ワールドトランスフォームの初期化
//	worldTransform_.Initialize();
//
//	worldTransform_.translation_.z = 0.5f;
//}
//
//void Enemy::Update(){
//
//	if (enemyMove_ == true) {
//
//		worldTransform_.translation_.x += EnemySpeed_;
//
//		EnemyMoveCount_ += 1;
//	}
//
//	if (EnemyMoveCount_ == 1) {
//
//		enemyMove_ = false;
//		EnemyMoveCount_ = 0;
//	}
//}
//
//void Enemy::Draw(ViewProjection& viewProjection) {
//	
//	model_->Draw(worldTransform_, viewProjection);
//
//}
//
//void Enemy::OnCollision() { isDead_ = true; }


