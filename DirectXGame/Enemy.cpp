#include "Enemy.h"
#include "GameScene.h"
#include <cassert>
#include "MathUtility.h"

#include "ImGuiManager.h"

#define NAX_MOVE 30

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

		//四隅の移動処理（縦）
		//  上に移動
		if (worldTransform_.translation_.z == 0 && worldTransform_.translation_.y < NAX_MOVE) {

			worldTransform_.translation_.y += EnemySpeed_;
		}

		// 奥方向に向かう処理
		else if (
		    worldTransform_.translation_.y == NAX_MOVE && worldTransform_.translation_.z < NAX_MOVE) {

			worldTransform_.translation_.z += EnemySpeed_;
		}

		// 下る処理
		else if (worldTransform_.translation_.z == NAX_MOVE && worldTransform_.translation_.y > 0) {

			worldTransform_.translation_.y -= EnemySpeed_;
		}
		// 　手前に来る
		else if (worldTransform_.translation_.z > 0 && worldTransform_.translation_.y == 0) {

			worldTransform_.translation_.z -= EnemySpeed_;
		}

		worldTransform_.translation_.z = Clamp(worldTransform_.translation_.z, 0, NAX_MOVE);
		worldTransform_.translation_.y = Clamp(worldTransform_.translation_.y, 0, NAX_MOVE);

	}

	worldTransform_.UpdateMatrix();

	/*ImGui::Begin("Enemy Debug");
	ImGui::Text(
	    "EnemyPosition  %f  %f  %f", worldTransform_.translation_.x,
	    worldTransform_.translation_.y, worldTransform_.translation_.z);
	ImGui::End();*/

}

void Enemy::Draw(ViewProjection& viewProjection) {

	if (isDead_ == true) {

		model_->Draw(worldTransform_, viewProjection);

	}

}




