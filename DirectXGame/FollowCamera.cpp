#include "FollowCamera.h"
#include "MathUtility.h"
#include <cmath>

void FollowCamera::Initialize() {

	viewProjection_.Initialize();
	viewProjection_.farZ = 1400.0f;
	viewProjection_.rotation_.x = ToRadian(90);
}

void FollowCamera::Update() {

	// XINPUT_STATE joyState;

	// if (Input::GetInstance()->GetJoystickState(0, joyState)) {
	//	viewProjection_.rotation_.y += (float)joyState.Gamepad.sThumbRX / SHRT_MAX * FollowSpeed;
	//	viewProjection_.rotation_.x += (float)joyState.Gamepad.sThumbRY / SHRT_MAX * FollowSpeed;
	//	viewProjection_.rotation_.z = 0.0f;
	// }

	if (target_) {

		Vector3 offset = {0.0f, 20.0f, 0.0f};

		// Matrix4x4 rotate = MakeRotateYMatrix(viewProjection_.rotation_.y);
		// Matrix4x4 rotate1 = MakeRotateXMatrix(viewProjection_.rotation_.x);
		// MakeRotateMatrix(tarzzzz)
		// offset = TransformNormal(offset, MakeRotateYMatrix(viewProjection_.rotation_.x));
		////offset = TransformNormal(offset, MakeRotateXMatrix(viewProjection_.rotation_.x));

		//viewProjection_.rotation_ = Add(target_->rotation_, {ToRadian(180), 0.0f, 0.0f});
		viewProjection_.translation_ = Add(target_->translation_, offset);
	}
	viewProjection_.UpdateMatrix();
}