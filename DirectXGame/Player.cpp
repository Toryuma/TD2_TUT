#include "Player.h"
#include "ImGuiManager.h"
#include "MathUtility.h"
#include <cassert>

#define NAX_MOVE 30

void Player::Initialize(Model* model) {

	assert(model);

	model_ = model;

	worldTransform_.Initialize();
	worldTransform_.translation_.x = 0.0f;
	worldTransform_.translation_.y = 0.0f;
	worldTransform_.translation_.z = 0.0f;
}

void Player::Update() {
	Vector3 move = {0};
	XINPUT_STATE joyState;

	if (Input::GetInstance()->GetJoystickState(0, joyState)) {

		const float speed = 0.3f;

		move = {
		    (float)joyState.Gamepad.sThumbLX / SHRT_MAX * speed, 0.0f,
		    (float)joyState.Gamepad.sThumbLY / SHRT_MAX * speed};

		move = Multiply(speed, Normalize(move));
	}
	
	// 十字ー等で入力したときにmoveの値を変える
	if (Input::GetInstance()->PushKey(DIK_UP)) {

		move.z += playerSpeed_;
	}

	else if (Input::GetInstance()->PushKey(DIK_DOWN)) {

		move.z -= playerSpeed_;
	}

	else if (Input::GetInstance()->PushKey(DIK_RIGHT)) {

		move.x += playerSpeed_;
	}

	else if (Input::GetInstance()->PushKey(DIK_LEFT)) {

		move.x -= playerSpeed_;
	}

	// 四隅の移動処理

	// 上入力したとき
	if (move.z > 0) {

		// 上に移動
		if (worldTransform_.translation_.z == 0 && worldTransform_.translation_.y < NAX_MOVE) {

			worldTransform_.translation_.y += playerSpeed_;
		}

		// 奥方向に向かう処理
		else if (
		    worldTransform_.translation_.y == NAX_MOVE &&
		    worldTransform_.translation_.z < NAX_MOVE) {

			worldTransform_.translation_.z += playerSpeed_;
		}

		// 下る処理
		else if (worldTransform_.translation_.z == NAX_MOVE && worldTransform_.translation_.y > 0) {

			worldTransform_.translation_.y -= playerSpeed_;
		}
		// 　手前に来る
		else if (worldTransform_.translation_.z > 0 && worldTransform_.translation_.y == 0) {

			worldTransform_.translation_.z -= playerSpeed_;
		}

		worldTransform_.translation_.z = Clamp(worldTransform_.translation_.z, 0, NAX_MOVE);
		worldTransform_.translation_.y = Clamp(worldTransform_.translation_.y, 0, NAX_MOVE);
	}
	// 下に入力したときに
	else if (move.z < 0) {

		// 奥に移動
		if (worldTransform_.translation_.z < NAX_MOVE && worldTransform_.translation_.y == 0) {

			worldTransform_.translation_.z += playerSpeed_;
		}

		// 上に向かう処理(奥)
		else if (
		    worldTransform_.translation_.z == NAX_MOVE &&
		    worldTransform_.translation_.y < NAX_MOVE) {

			worldTransform_.translation_.y += playerSpeed_;
		}

		// 手前に戻る処理
		else if (worldTransform_.translation_.z > 0 && worldTransform_.translation_.y == NAX_MOVE) {

			worldTransform_.translation_.z -= playerSpeed_;
		}

		//  下に戻る（手前）
		else if (worldTransform_.translation_.z < NAX_MOVE && worldTransform_.translation_.y > 0) {

			worldTransform_.translation_.y -= playerSpeed_;
		}

		worldTransform_.translation_.z = Clamp(worldTransform_.translation_.z, 0, NAX_MOVE);
		worldTransform_.translation_.y = Clamp(worldTransform_.translation_.y, 0, NAX_MOVE);
	}

	// 横の移動処理

	// 順
	else if (move.x > 0) {

		// 横に移動
		if (worldTransform_.translation_.z == 0 && worldTransform_.translation_.x < NAX_MOVE &&
		    worldTransform_.translation_.y < NAX_MOVE) {

			worldTransform_.translation_.x += playerSpeed_;
		}

		// 横に移動（上）
		else if (
		    worldTransform_.translation_.z == 0 && worldTransform_.translation_.x < NAX_MOVE &&
		    worldTransform_.translation_.y > NAX_MOVE) {

			worldTransform_.translation_.x += playerSpeed_;
		}

		// 横に移動（奥）
		else if (
		    worldTransform_.translation_.z >= NAX_MOVE &&
		    worldTransform_.translation_.x < NAX_MOVE &&
		    worldTransform_.translation_.y < NAX_MOVE) {

			worldTransform_.translation_.x += playerSpeed_;
		}

		// 横に移動（奥、上）
		else if (
		    worldTransform_.translation_.z > NAX_MOVE &&
		    worldTransform_.translation_.x < NAX_MOVE &&
		    worldTransform_.translation_.y > NAX_MOVE) {

			worldTransform_.translation_.x += playerSpeed_;
			worldTransform_.translation_.y = 30.0f;
		}

		worldTransform_.translation_.z = Clamp(worldTransform_.translation_.z, 0, NAX_MOVE);
		worldTransform_.translation_.y = Clamp(worldTransform_.translation_.y, 0, NAX_MOVE);
		worldTransform_.translation_.x = Clamp(worldTransform_.translation_.x, 0, NAX_MOVE);
	}
	// 反
	else if (move.x < 0) {

		// 横に移動
		if (worldTransform_.translation_.z == 0 && worldTransform_.translation_.x > 0 &&
		    worldTransform_.translation_.y < NAX_MOVE) {

			worldTransform_.translation_.x -= playerSpeed_;
		}

		// 横に移動（上）
		else if (
		    worldTransform_.translation_.z == 0 && worldTransform_.translation_.x < NAX_MOVE &&
		    worldTransform_.translation_.y >= NAX_MOVE) {

			worldTransform_.translation_.x -= playerSpeed_;
		}

		// 横に移動（奥）
		else if (
		    worldTransform_.translation_.z == NAX_MOVE &&
		    worldTransform_.translation_.x < NAX_MOVE &&
		    worldTransform_.translation_.y < NAX_MOVE) {

			worldTransform_.translation_.x -= playerSpeed_;
		}

		// 横に移動（奥、上）
		else if (
		    worldTransform_.translation_.z == NAX_MOVE &&
		    worldTransform_.translation_.x < NAX_MOVE &&
		    worldTransform_.translation_.y >= NAX_MOVE) {

			worldTransform_.translation_.x -= playerSpeed_;
		}

		worldTransform_.translation_.z = Clamp(worldTransform_.translation_.z, 0, NAX_MOVE);
		worldTransform_.translation_.y = Clamp(worldTransform_.translation_.y, 0, NAX_MOVE);
		worldTransform_.translation_.x = Clamp(worldTransform_.translation_.x, 0, NAX_MOVE);
	}

	worldTransform_.UpdateMatrix();

	ImGui::Begin("Player Debug");
	ImGui::Text(
	    "PlayerPosition  %f  %f  %f", worldTransform_.translation_.x,
	    worldTransform_.translation_.y, worldTransform_.translation_.z);
	ImGui::Text("move  %f  %f  %f", move.x, move.y, move.z);
	ImGui::End();
}

void Player::Draw(ViewProjection& viewProjection) { 
	
	model_->Draw(worldTransform_, viewProjection); 

}

void Player::OnCollision() {}
