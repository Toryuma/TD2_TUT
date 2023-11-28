#include "Enemy.h"
#include "GameScene.h"
#include <cassert>

#include "ImGuiManager.h"

void Enemy::Initialize(Model* model) { 

	assert(model);
	
	model_ = model; 

	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();

	worldTransform_.translation_.x = 0.0f;
	worldTransform_.translation_.y = 0.0f;
	worldTransform_.translation_.z = 0.0f;
}

void Enemy::Update(){

	if (isDead_ == true) {

		//worldTransform_.translation_.z += EnemySpeed_;

		//四隅の移動処理（縦）


	}

	ImGui::Begin("Enemy Debug");
	ImGui::Text(
	    "EnemyPosition  %f  %f  %f", worldTransform_.translation_.x,
	    worldTransform_.translation_.y, worldTransform_.translation_.z);
	ImGui::End();

}

void Enemy::OnCollision() { 

	isDead_ = true; 

}

void Enemy::Draw(ViewProjection& viewProjection) {

	if (isDead_ == true) {

		model_->Draw(worldTransform_, viewProjection);

	}

}




