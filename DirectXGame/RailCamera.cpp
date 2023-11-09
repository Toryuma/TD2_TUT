#include "RailCamera.h"
#include "ViewProjection.h"
#include "ImGuiManager.h"
#include "MyMath.h"

void RailCamera::Initialize() {
	// ワールドトランスフォームの初期設定
	worldtransform_.translation_.z = -10;
	// ワールドトランスフォームの初期化
	worldtransform_.Initialize();

	// ビュープロジェクションの初期化
	viewprojection_.Initialize();
	viewprojection_.farZ = 1200.0f;
}

void RailCamera::Update() {
	// ワールドトランスフォームのワールド行列再計算
	worldtransform_.UpdateMatrix();

	// カメラオブジェクトのワールド行列からビュー行列を計算する
	viewprojection_.matView = Inverse(worldtransform_.matWorld_);

	viewprojection_.UpdateMatrix();

	//カメラの座標を画面表示する処理
	// ImGui::Begin("Camera");

	// ImGui::SliderFloat3("translation", &worldtransform_.translation_.x, -100, 100);
	// ImGui::SliderFloat3("rotation", &worldtransform_.rotation_.x, -6.28f, 6.28f);

	// ImGui::End();
}