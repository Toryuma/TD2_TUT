#include "Player.h"
#include <cassert>
#include "MathUtility.h"

void Player::Initialize(Model* model) {

	assert(model);

	model_ = model;

	worldTransform_.Initialize();
	worldTransform_.translation_.y = 0.2f;
}

void Player::Update() {

	XINPUT_STATE joyState;

	if (Input::GetInstance()->GetJoystickState(0, joyState)) {

		const float speed = 0.3f;

		Vector3 move = {
		    (float)joyState.Gamepad.sThumbLX / SHRT_MAX * speed, 0.0f,
		    (float)joyState.Gamepad.sThumbLY / SHRT_MAX * speed};

		move = Multiply(speed, Normalize(move));

		worldTransform_.rotation_.y = std::atan2(-move.x, -move.y);

		worldTransform_.translation_ = Add(worldTransform_.translation_, move);
	}

	worldTransform_.UpdateMatrix();
}

void Player::Draw(ViewProjection& viewProjection) {

	model_->Draw(worldTransform_, viewProjection);

}
