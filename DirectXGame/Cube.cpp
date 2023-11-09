#include "Cube.h"
#include "Input.h"
#include "MyMath.h"
#include <Xinput.h>
#include <cassert>

Vector3 Cube::GetWorldPosition() {
	// ワールド座標を入れる関数
	Vector3 worldPos;
	// ワールド行列の平行移動成分を取得
	worldPos.x = worldtransform_.matWorld_.m[3][0];
	worldPos.y = worldtransform_.matWorld_.m[3][1];
	worldPos.z = worldtransform_.matWorld_.m[3][2];

	return worldPos;
}

Cube::Cube() {}
Cube::~Cube() {}

void Cube::Initialize(Model* model, uint32_t textureHandle) {
	assert(model);
	model_ = model;
	textureHandle_ = textureHandle;

	// ワールドトランスフォームの初期化
	worldtransform_.Initialize();
	// X,Y,Z方向のスケーリングを設定
	worldtransform_.scale_ = {1.0f, 1.0f, 1.0f};
	worldtransform_.translation_ = {0.0f, 2.0f, -5.0f};
}

void Cube::Update() {
	// ゲームパッドの状態を得る変数(XINPUT)
	XINPUT_STATE joyState;

	// ゲームパッド状態
	if (Input::GetInstance()->GetJoystickState(0, joyState)) {
		// キャラクターの速さ
		const float Speed = 0.3f;
		// 移動量
		Vector3 move = {
		    (float)joyState.Gamepad.sThumbLX / SHRT_MAX * Speed, 0.0f,
		    (float)joyState.Gamepad.sThumbLY / SHRT_MAX * Speed};
		// 移動量に速さを反映
		move = Normalize(move);
		move = Multiply2(Speed, move);

		// 回転行列
		Matrix4x4 rotateMatrix = MakeRotateMatrix(viewprojection_->rotation_);
		// 移動ベクトルをカメラの角度だけ回転
		move = TransformNormal(move, rotateMatrix);

		// 移動
		worldtransform_.translation_ = Add(worldtransform_.translation_, move);

		// playerのY軸周り角度(θy)
		worldtransform_.rotation_.y = std::atan2(move.x, move.z);
	}
	// 行列を定数バッファに転送
	worldtransform_.UpdateMatrix();
}

void Cube::Draw(ViewProjection& viewprojection) {
	model_->Draw(worldtransform_, viewprojection, textureHandle_);
}
